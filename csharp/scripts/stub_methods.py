#!/usr/bin/env python3
"""
Replaces method bodies in C# solution files with a
// TODO + throw NotImplementedException stub.
Tests will compile and run, showing failures for each
unimplemented method individually.

Skips:
  - *Tests.cs files
  - Shared.cs (infrastructure helpers)
  - Methods named Equals, GetHashCode, ToString, CompareTo, Compare
    (equality/ordering boilerplate)

Usage: stub_methods.py <folder>
"""

import sys
import os
import re
import glob

SKIP_NAMES = {'Shared.cs'}

# Equality/ordering methods — stubbing these breaks infrastructure
BOILERPLATE_METHODS = {
    'Equals', 'GetHashCode', 'ToString', 'CompareTo', 'Compare',
}

TYPE_KEYWORDS = {
    'namespace', 'class', 'struct', 'interface', 'record', 'enum',
}

STUB_THROW = 'throw new System.NotImplementedException();'


# ---------------------------------------------------------------------------
# Lexer helpers
# ---------------------------------------------------------------------------

def mask_non_code(content):
    """
    Returns a same-length copy of content with comments, string/char
    literals and preprocessor lines blanked out, so structural scanning
    only ever sees real braces, parens and semicolons.
    """
    out = list(content)
    n = len(content)
    i = 0

    def blank(start, end):
        for j in range(start, min(end, n)):
            if out[j] != '\n':
                out[j] = ' '

    while i < n:
        c = content[i]
        two = content[i:i + 2]

        if two == '//':
            end = content.find('\n', i)
            end = n if end == -1 else end
            blank(i, end)
            i = end
        elif two == '/*':
            end = content.find('*/', i + 2)
            end = n if end == -1 else end + 2
            blank(i, end)
            i = end
        elif c == '#' and content[:i].rsplit('\n', 1)[-1].strip() == '':
            end = content.find('\n', i)
            end = n if end == -1 else end
            blank(i, end)
            i = end
        elif c == '"' or (c in '$@' and re.match(r'[$@]+"', content[i:])):
            start = i
            prefix = re.match(r'[$@]*', content[i:]).group(0)
            i += len(prefix)
            quotes = len(re.match(r'"+', content[i:]).group(0))
            if quotes >= 3:
                # raw string literal: ends at the same run of quotes
                end = content.find('"' * quotes, i + quotes)
                i = n if end == -1 else end + quotes
            elif '@' in prefix:
                # verbatim string: "" is an escaped quote
                i += 1
                while i < n:
                    if content[i] == '"':
                        if content[i:i + 2] == '""':
                            i += 2
                            continue
                        i += 1
                        break
                    i += 1
            else:
                i += 1
                while i < n:
                    if content[i] == '\\':
                        i += 2
                    elif content[i] == '"':
                        i += 1
                        break
                    else:
                        i += 1
            blank(start, i)
        elif c == "'":
            start = i
            i += 1
            while i < n:
                if content[i] == '\\':
                    i += 2
                elif content[i] == "'":
                    i += 1
                    break
                else:
                    i += 1
            blank(start, i)
        else:
            i += 1

    return ''.join(out)


def find_matching(masked, i):
    """Returns the index of the bracket that closes the one at i."""
    pairs = {'{': '}', '(': ')', '[': ']'}
    open_ch = masked[i]
    close_ch = pairs[open_ch]
    depth = 0
    while i < len(masked):
        if masked[i] == open_ch:
            depth += 1
        elif masked[i] == close_ch:
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return len(masked) - 1


def collapse_groups(header):
    """Replaces every balanced (...) and [...] group with () / []."""
    out = []
    i = 0
    while i < len(header):
        c = header[i]
        if c in '([':
            end = find_matching(header, i)
            out.append('()' if c == '(' else '[]')
            i = end + 1
        else:
            out.append(c)
            i += 1
    return ''.join(out)


# ---------------------------------------------------------------------------
# Declaration classification
# ---------------------------------------------------------------------------

def is_type_header(header):
    flat = collapse_groups(header)
    # generic constraints ("where T : class") are not type declarations
    flat = re.split(r'\bwhere\b', flat)[0]
    return bool(TYPE_KEYWORDS & set(re.findall(r'[A-Za-z_]\w*', flat)))


def has_initializer(header):
    """True if the declaration assigns a value (field/property initializer)."""
    flat = collapse_groups(header)
    if 'operator' in re.findall(r'[A-Za-z_]\w*', flat):
        return False  # the '=' belongs to an operator name such as ==
    return '=' in flat


def is_method_header(header):
    if '()' not in collapse_groups(header):
        return False  # property, indexer, field
    return not has_initializer(header)


def method_name(header):
    flat = collapse_groups(header)
    match = re.search(r'([A-Za-z_]\w*)\s*(<[^()]*>)?\s*\(\)', flat)
    return match.group(1) if match else ''


def find_arrow(masked, start, end):
    """Finds the first '=>' in masked[start:end] outside any brackets."""
    i = start
    while i < end:
        c = masked[i]
        if c in '([{':
            i = find_matching(masked, i) + 1
        elif masked[i:i + 2] == '=>':
            return i
        else:
            i += 1
    return -1


def find_methods(masked, start, end):
    """
    Yields (kind, header, a, b) for every method declared directly in a
    type body within masked[start:end]:
      - ('block', header, open_brace, close_brace)
      - ('arrow', header, expr_start, semicolon)
    """
    i = start
    header_start = start
    while i < end:
        c = masked[i]
        if c in '([':
            i = find_matching(masked, i) + 1
        elif c == ';':
            arrow = find_arrow(masked, header_start, i)
            if arrow != -1:
                header = masked[header_start:arrow]
                if is_method_header(header):
                    yield ('arrow', header, arrow + 2, i)
            i += 1
            header_start = i
        elif c == '{':
            close = find_matching(masked, i)
            header = masked[header_start:i]
            if is_type_header(header):
                yield from find_methods(masked, i + 1, close)
                header_start = close + 1
            elif has_initializer(header):
                # initializer or expression body: declaration runs on to ';'
                pass
            else:
                if is_method_header(header):
                    yield ('block', header, i, close)
                header_start = close + 1
            i = close + 1
        elif c == '}':
            i += 1
            header_start = i
        else:
            i += 1


# ---------------------------------------------------------------------------
# File processing
# ---------------------------------------------------------------------------

def line_indent(content, pos):
    line_start = content.rfind('\n', 0, pos) + 1
    return re.match(r'[ \t]*', content[line_start:]).group(0)


def stub_file(filepath):
    with open(filepath, 'r', encoding='utf-8-sig') as f:
        content = f.read()

    masked = mask_non_code(content)
    methods = list(find_methods(masked, 0, len(masked)))
    if not methods:
        print(
            f"  No methods found in "
            f"{os.path.basename(filepath)}, skipping"
        )
        return

    stubs = []
    skipped = 0
    for kind, header, a, b in methods:
        if method_name(header) in BOILERPLATE_METHODS:
            skipped += 1
            continue

        if kind == 'block':
            indent = line_indent(content, b)
            body = (
                f"{{\n{indent}    // TODO:\n"
                f"{indent}    {STUB_THROW}\n{indent}}}"
            )
            stubs.append((a, b + 1, body))
        else:
            stubs.append((a, b + 1, f" {STUB_THROW}"))

    if not stubs:
        print(
            f"  Only boilerplate methods in "
            f"{os.path.basename(filepath)}, skipping"
        )
        return

    result = content
    for start, end, replacement in reversed(stubs):
        result = result[:start] + replacement + result[end:]

    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(result)

    fn_word = "method" if len(stubs) == 1 else "methods"
    note = f" ({skipped} boilerplate skipped)" if skipped else ""
    print(
        f"  Stubbed {len(stubs)} {fn_word} in "
        f"{os.path.basename(filepath)}{note}"
    )


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main():
    if len(sys.argv) < 2:
        print("Usage: stub_methods.py <folder>")
        sys.exit(1)

    folder = sys.argv[1]

    if not os.path.isdir(folder):
        print(f"Error: directory '{folder}' not found")
        sys.exit(1)

    cs_files = sorted(glob.glob(os.path.join(folder, '*.cs')))
    solution_files = [
        f for f in cs_files
        if not os.path.basename(f).endswith('Tests.cs')
        and os.path.basename(f) not in SKIP_NAMES
    ]

    if not solution_files:
        print(f"No solution files found in '{folder}'")
        sys.exit(1)

    print(f"Stubbing {len(solution_files)} file(s) in '{folder}'...")
    for f in solution_files:
        stub_file(f)
    print(
        "Done! Use 'git diff' to review and "
        "'git checkout -- <folder>' to restore."
    )


if __name__ == '__main__':
    main()
