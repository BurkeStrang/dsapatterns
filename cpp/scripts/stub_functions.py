#!/usr/bin/env python3
"""
Replaces function bodies in C++ solution files with a
// TODO + `return {};` stub.
Tests will compile and run, showing failures for each
unimplemented function individually.

Functions are found at file scope and inside namespaces, structs and
classes, so member functions are stubbed too. `void` functions,
constructors and destructors get a stub with no return.

Skips:
  - *_test.cpp files
  - shared.cpp / shared.hpp (infrastructure helpers)

Limitation: a constructor whose member initializer list uses braces
(`: items{}`) is not recognised; write `: items()` instead.

Usage: stub_functions.py <folder>
"""

import glob
import os
import re
import sys

SKIP_NAMES = {'shared.cpp'}

# Words that can come before a return type without being part of it
QUALIFIERS = {
    'static', 'inline', 'constexpr', 'consteval', 'virtual', 'friend',
    'explicit', 'extern',
}

# Headers that open a block which is not a function body
CONTROL_WORDS = {'if', 'for', 'while', 'switch', 'catch', 'do', 'else', 'try'}
SCOPE_WORDS = {'namespace', 'struct', 'class', 'union', 'enum'}


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
            # preprocessor line, including backslash continuations
            end = i
            while True:
                end = content.find('\n', end)
                if end == -1:
                    end = n
                    break
                if content[end - 1] != '\\':
                    break
                end += 1
            blank(i, end)
            i = end
        elif c == "'" and i > 0 and content[i - 1].isalnum():
            i += 1  # a digit separator such as 1'000'000
        elif c in '"\'':
            start = i
            i += 1
            while i < n:
                if content[i] == '\\':
                    i += 2
                elif content[i] == c:
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


# ---------------------------------------------------------------------------
# Function detection
# ---------------------------------------------------------------------------

def first_word(header):
    match = re.match(r'\s*([A-Za-z_]\w*)', header)
    return match.group(1) if match else ''


def strip_template_prefix(header):
    """Drops a leading `template <...>` from a header."""
    stripped = header.lstrip()
    if not stripped.startswith('template'):
        return header
    depth = 0
    for i, c in enumerate(stripped):
        if c == '<':
            depth += 1
        elif c == '>':
            depth -= 1
            if depth == 0:
                return stripped[i + 1:]
    return header


def is_function_header(header):
    header = strip_template_prefix(header)
    paren = header.find('(')
    if paren == -1:
        return False  # struct, class, namespace, enum
    if first_word(header) in CONTROL_WORDS | SCOPE_WORDS:
        return False
    return '=' not in header[:paren]  # an '=' means an initializer


def find_functions(masked, start=0, end=None):
    """
    Yields (header, open_brace, close_brace) for every function defined
    between start and end, looking inside namespaces, structs and classes.
    """
    end = len(masked) if end is None else end
    i = start
    header_start = start
    while i < end:
        c = masked[i]
        if c in ';}':
            i += 1
            header_start = i
        elif c == ':' and masked[header_start:i].strip() in (
            'public', 'private', 'protected'
        ):
            i += 1
            header_start = i
        elif c == '{':
            close = find_matching(masked, i)
            header = masked[header_start:i]
            if is_function_header(header):
                yield (header, i, close)
                header_start = close + 1
            elif first_word(strip_template_prefix(header)) in SCOPE_WORDS:
                yield from find_functions(masked, i + 1, close)
                header_start = close + 1
            # otherwise it is an initializer that runs on to ';'
            i = close + 1
        else:
            i += 1


def extract_func_info(header):
    """Returns (name, return_type) from a function header."""
    header = strip_template_prefix(header)
    before_params = header[:header.find('(')]
    match = re.search(r'(~?[A-Za-z_][\w:]*|operator\s*\S+)\s*$', before_params)
    if not match:
        return '', ''
    name = match.group(1)
    return_type = before_params[:match.start()]
    words = [w for w in return_type.split() if w not in QUALIFIERS]
    return name, ' '.join(words).strip()


def make_stub_body(return_type, indent):
    """
    Returns the text between the braces; indent is the indentation of the
    line the function's opening brace is on.
    """
    lines = [f'{indent}    // TODO:']
    if return_type and return_type != 'void':
        lines.append(f'{indent}    return {{}};')
    return '\n' + '\n'.join(lines) + '\n' + indent


def line_indent(content, i):
    """Returns the leading whitespace of the line that holds index i."""
    line_start = content.rfind('\n', 0, i) + 1
    line = content[line_start:i]
    return line[:len(line) - len(line.lstrip())]


# ---------------------------------------------------------------------------
# File processing
# ---------------------------------------------------------------------------

def stub_file(filepath):
    with open(filepath, 'r') as f:
        content = f.read()

    masked = mask_non_code(content)
    stubs = []
    for header, brace_start, brace_end in find_functions(masked):
        name, return_type = extract_func_info(header)
        if not name or name == 'main':
            continue
        indent = line_indent(content, brace_start)
        body = make_stub_body(return_type, indent)
        stubs.append((brace_start, brace_end, body))

    if not stubs:
        print(
            f"  No functions found in "
            f"{os.path.basename(filepath)}, skipping"
        )
        return

    result = content
    for brace_start, brace_end, stub_body in reversed(stubs):
        result = result[:brace_start + 1] + stub_body + result[brace_end:]

    with open(filepath, 'w') as f:
        f.write(result)

    fn_word = "function" if len(stubs) == 1 else "functions"
    print(
        f"  Stubbed {len(stubs)} {fn_word} in "
        f"{os.path.basename(filepath)}"
    )


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main():
    if len(sys.argv) < 2:
        print("Usage: stub_functions.py <folder>")
        sys.exit(1)

    folder = sys.argv[1]

    if not os.path.isdir(folder):
        print(f"Error: directory '{folder}' not found")
        sys.exit(1)

    cpp_files = sorted(glob.glob(os.path.join(folder, '*.cpp')))
    solution_files = [
        f for f in cpp_files
        if not os.path.basename(f).endswith('_test.cpp')
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
