#!/usr/bin/env python3
"""
Replaces function bodies in Rust solution files with a
// TODO + todo!() stub.
Tests will compile and run, showing a failure for each
unimplemented function individually.

Skips:
  - *_test.rs files
  - mod.rs (the list of files in the pattern)
  - shared.rs (infrastructure helpers)

Usage: stub_functions.py <folder>
"""

import sys
import os
import re
import glob

SKIP_NAMES = {'mod.rs', 'shared.rs'}

# Stubbed functions leave their parameters, imports, and helper types unused;
# this keeps the compiler quiet about that until the code is written back.
ALLOW_UNUSED = '#![allow(unused, clippy::all)] // practice mode\n\n'

FN_KEYWORD = re.compile(r'\bfn\s+(\w+)')


# ---------------------------------------------------------------------------
# Lexer helpers
# ---------------------------------------------------------------------------

def skip_string(content, i):
    """Skip a "..." string starting at the opening quote."""
    i += 1
    while i < len(content):
        if content[i] == '\\':
            i += 2
        elif content[i] == '"':
            return i + 1
        else:
            i += 1
    return i


def skip_raw_string(content, i):
    """Skip a r"..." or r#"..."# string starting at the 'r'."""
    j = i + 1
    hashes = 0
    while j < len(content) and content[j] == '#':
        hashes += 1
        j += 1
    end = content.find('"' + '#' * hashes, j + 1)
    return len(content) if end == -1 else end + 1 + hashes


def skip_quote(content, i):
    """Skip a 'x' character, or just the quote of a 'lifetime."""
    if content.startswith('\\', i + 1):
        end = content.find("'", i + 3)
        return len(content) if end == -1 else end + 1
    if content.startswith("'", i + 2):
        return i + 3
    return i + 1  # a lifetime such as 'a


def skip_line_comment(content, i):
    end = content.find('\n', i)
    return len(content) if end == -1 else end


def skip_block_comment(content, i):
    end = content.find('*/', i + 2)
    return len(content) if end == -1 else end + 2


def advance(content, i):
    """
    If position i starts a string, character, or comment, return the position
    just past it. Otherwise return None.
    """
    c = content[i]
    if c == '"':
        return skip_string(content, i)
    if c == 'r' and re.match(r'r#*"', content[i:i + 8]) and (
            i == 0 or not (content[i - 1].isalnum() or content[i - 1] == '_')):
        return skip_raw_string(content, i)
    if c == "'":
        return skip_quote(content, i)
    if content.startswith('//', i):
        return skip_line_comment(content, i)
    if content.startswith('/*', i):
        return skip_block_comment(content, i)
    return None


def find_matching_brace(content, open_pos):
    """Return the position of the '}' that closes the '{' at open_pos."""
    depth = 0
    i = open_pos
    while i < len(content):
        skipped = advance(content, i)
        if skipped is not None:
            i = skipped
            continue
        if content[i] == '{':
            depth += 1
        elif content[i] == '}':
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1


# ---------------------------------------------------------------------------
# Function detection
# ---------------------------------------------------------------------------

def find_functions(content):
    """
    Return (name, body_open, body_close) for every function that is not
    inside another function, where body_open and body_close are the positions
    of its braces. Functions inside an impl block are included.
    """
    functions = []
    i = 0
    while i < len(content):
        skipped = advance(content, i)
        if skipped is not None:
            i = skipped
            continue

        match = FN_KEYWORD.match(content, i)
        if not match or (i > 0 and (content[i - 1].isalnum()
                                    or content[i - 1] == '_')):
            i += 1
            continue

        # the body starts at the first '{' after the signature; a ';' first
        # means a declaration without a body. A ';' inside brackets belongs
        # to an array type such as [i32; 2], so keep track of the nesting
        j = match.end()
        depth = 0
        while j < len(content):
            if depth == 0 and content[j] in '{;':
                break
            if content[j] in '([':
                depth += 1
            elif content[j] in ')]':
                depth -= 1
            j = advance(content, j) or j + 1
        if j >= len(content) or content[j] == ';':
            i = j
            continue

        body_close = find_matching_brace(content, j)
        if body_close == -1:
            break
        functions.append((match.group(1), j, body_close))
        i = body_close + 1  # skip the body, and any functions nested in it

    return functions


def stub_body(content, body_open):
    """Build the stub, indented one level deeper than the function."""
    line_start = content.rfind('\n', 0, body_open) + 1
    # the signature may span several lines; the closing ')' or the 'fn' line
    # that the '{' sits on has the function's own indentation
    line = content[line_start:body_open]
    indent = line[:len(line) - len(line.lstrip())]
    inner = indent + '    '
    return f'{{\n{inner}// TODO:\n{inner}todo!()\n{indent}}}'


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def stub_file(filepath):
    with open(filepath) as f:
        original = f.read()

    functions = find_functions(original)
    if not functions:
        return 0

    content = original
    # replace from the last function to the first so positions stay valid
    for _, body_open, body_close in reversed(functions):
        content = (content[:body_open] + stub_body(content, body_open)
                   + content[body_close + 1:])

    if not content.startswith(ALLOW_UNUSED):
        content = ALLOW_UNUSED + content

    with open(filepath, 'w') as f:
        f.write(content)
    return len(functions)


def main():
    if len(sys.argv) != 2:
        print(f'Usage: {sys.argv[0]} <folder>')
        sys.exit(1)

    folder = sys.argv[1].rstrip('/')
    if not os.path.isdir(folder):
        print(f"Error: folder '{folder}' not found")
        sys.exit(1)

    files = sorted(
        f for f in glob.glob(os.path.join(folder, '*.rs'))
        if not f.endswith('_test.rs')
        and os.path.basename(f) not in SKIP_NAMES
    )
    if not files:
        print(f"No solution files found in '{folder}'")
        sys.exit(1)

    for filepath in files:
        count = stub_file(filepath)
        print(f'  stubbed {count} function(s): {filepath}')

    print(f'\nDone. Run: make test P={folder}')
    print(f'Restore with: git checkout -- {folder}/')


if __name__ == '__main__':
    main()
