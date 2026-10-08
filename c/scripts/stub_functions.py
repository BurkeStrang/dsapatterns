#!/usr/bin/env python3
"""
Replaces function bodies in C solution files with a
// TODO + zero-value return stub.
Tests will compile and run, showing failures for each
unimplemented function individually.

Skips:
  - *_test.c files
  - shared.c / shared.h (infrastructure helpers)

Usage: stub_functions.py <folder>
"""

import sys
import os
import re
import glob

SKIP_NAMES = {'shared.c'}

# Words that can come before a return type without being part of it
QUALIFIERS = {'static', 'inline', 'extern', 'const', 'volatile'}

# Return types made only of these words can be stubbed with `return 0;`
NUMERIC_WORDS = {
    'int', 'long', 'short', 'char', 'unsigned', 'signed', 'float', 'double',
    'size_t', 'ssize_t', 'ptrdiff_t', 'intptr_t', 'uintptr_t',
    'int8_t', 'int16_t', 'int32_t', 'int64_t',
    'uint8_t', 'uint16_t', 'uint32_t', 'uint64_t',
}


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

def find_functions(masked):
    """
    Yields (header, open_brace, close_brace) for every function defined
    at file scope.
    """
    i = 0
    header_start = 0
    while i < len(masked):
        c = masked[i]
        if c == ';':
            i += 1
            header_start = i
        elif c == '{':
            close = find_matching(masked, i)
            header = masked[header_start:i]
            if is_function_header(header):
                yield (header, i, close)
                header_start = close + 1
            # otherwise it is a struct/enum/initializer that runs on to ';'
            i = close + 1
        else:
            i += 1


def is_function_header(header):
    paren = header.find('(')
    if paren == -1:
        return False  # struct, union, enum
    return '=' not in header[:paren]  # an '=' means an initializer


def extract_func_info(header):
    """Returns (name, return_type) from a function header."""
    before_params = header[:header.find('(')]
    match = re.search(r'([A-Za-z_]\w*)\s*$', before_params)
    if not match:
        return '', ''
    name = match.group(1)
    return_type = before_params[:match.start()]
    words = [w for w in return_type.split() if w not in QUALIFIERS]
    return name, ' '.join(words).strip()


def make_stub_body(return_type):
    lines = ['    // TODO:']
    if return_type == 'void':
        pass
    elif '*' in return_type:
        lines.append('    return NULL;')
    elif return_type == 'bool':
        lines.append('    return false;')
    elif set(return_type.split()) <= NUMERIC_WORDS:
        lines.append('    return 0;')
    else:
        # a struct, union, enum or typedef: return a zeroed value of it
        lines.append(f'    return ({return_type}){{0}};')
    return '\n' + '\n'.join(lines) + '\n'


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
        if not name or not return_type or name == 'main':
            continue
        stubs.append((brace_start, brace_end, make_stub_body(return_type)))

    if not stubs:
        print(
            f"  No functions found in "
            f"{os.path.basename(filepath)}, skipping"
        )
        return

    result = content
    for brace_start, brace_end, stub_body in reversed(stubs):
        result = result[:brace_start + 1] + stub_body + result[brace_end:]

    # a stub that returns NULL needs a header that defines it
    uses_null = any('return NULL;' in body for _, _, body in stubs)
    if uses_null and '<stddef.h>' not in result:
        result = '#include <stddef.h>\n' + result

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

    c_files = sorted(glob.glob(os.path.join(folder, '*.c')))
    solution_files = [
        f for f in c_files
        if not os.path.basename(f).endswith('_test.c')
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
