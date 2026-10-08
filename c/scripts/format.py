#!/usr/bin/env python3
"""
Formats the C sources: clang-format first (Allman braces, see
.clang-format), then one extra step clang-format can't do, which puts every
function's parameter list on its own lines:

    double *find_averages
    (
        int k,
        const int *arr
    )
    {

Functions that take no parameters keep `name(void)` on one line.

Usage: format.py [--check] <file>...

With --check nothing is written; the files that are not formatted are
listed and the exit code is 1.
"""

import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from stub_functions import find_matching, mask_non_code  # noqa: E402

INDENT = '    '


def is_ident_char(c):
    return c.isalnum() or c == '_'


def split_params(content, masked, start, end):
    """Splits content[start:end] on the commas that separate parameters."""
    params = []
    depth = 0
    piece_start = start
    for i in range(start, end):
        c = masked[i]
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        elif c == ',' and depth == 0:
            params.append(content[piece_start:i])
            piece_start = i + 1
    params.append(content[piece_start:end])
    return [' '.join(p.split()) for p in params]


def join_prefix(text):
    """Joins a return type and name that were split over several lines."""
    joined = ''
    for part in text.split():
        if joined and not joined.endswith('*'):
            joined += ' '
        joined += part
    return joined


def signature_edit(content, masked, header_start, end, terminator):
    """
    Returns (start, stop, replacement) for the function declared in
    masked[header_start:end], or None if that text is not a function.
    """
    header = masked[header_start:end]
    paren = header.find('(')
    if paren == -1 or '=' in header[:paren] or '{' in header:
        return None
    if header.strip().startswith('typedef'):
        return None

    open_abs = header_start + paren
    before = header[:paren].rstrip()
    after = header[paren + 1:].lstrip()
    if not before or not is_ident_char(before[-1]) or after.startswith('*'):
        return None  # not `name(`, e.g. a function pointer

    close_abs = find_matching(masked, open_abs)
    if close_abs >= end or masked[close_abs + 1:end].strip() != '':
        return None
    if content[open_abs + 1:close_abs] != masked[open_abs + 1:close_abs]:
        return None  # a comment or string inside the parameter list

    decl_start = header_start + (len(header) - len(header.lstrip()))
    name_end = header_start + len(before)
    prefix = join_prefix(content[decl_start:name_end])

    params = split_params(content, masked, open_abs + 1, close_abs)
    if params in (['void'], ['']):
        signature = f"{prefix}({params[0]})"
    else:
        lines = ',\n'.join(INDENT + p for p in params)
        signature = f"{prefix}\n(\n{lines}\n)"

    signature += '\n' if terminator == '{' else ''
    return (decl_start, end, signature)


def format_signatures(content):
    masked = mask_non_code(content)
    edits = []
    i = 0
    header_start = 0
    while i < len(masked):
        c = masked[i]
        if c == ';':
            edit = signature_edit(content, masked, header_start, i, ';')
            if edit:
                edits.append(edit)
            i += 1
            header_start = i
        elif c == '{':
            close = find_matching(masked, i)
            edit = signature_edit(content, masked, header_start, i, '{')
            if edit:
                edits.append(edit)
                header_start = close + 1
            i = close + 1
        elif c == '(':
            i = find_matching(masked, i) + 1
        else:
            i += 1

    for start, stop, replacement in reversed(edits):
        content = content[:start] + replacement + content[stop:]
    return content


def clang_format(path, content):
    result = subprocess.run(
        ['clang-format', f'--assume-filename={path}'],
        input=content, capture_output=True, text=True, check=True,
    )
    return result.stdout


def main():
    args = sys.argv[1:]
    check = '--check' in args
    files = [a for a in args if a != '--check']
    if not files:
        print("Usage: format.py [--check] <file>...")
        sys.exit(1)

    unformatted = []
    for path in files:
        with open(path, 'r') as f:
            original = f.read()
        formatted = format_signatures(clang_format(path, original))
        if formatted == original:
            continue
        if check:
            unformatted.append(path)
        else:
            with open(path, 'w') as f:
                f.write(formatted)

    if unformatted:
        print("Not formatted (run 'make fmt'):")
        for path in unformatted:
            print(f"  {path}")
        sys.exit(1)


if __name__ == '__main__':
    main()
