#!/usr/bin/env python3
"""
Replaces function bodies in Go solution files with a // TODO + panic("TODO") stub.
Skips *_test.go files and shared infrastructure files (shared.go, share.go).

Usage: stub_functions.py <folder>
"""

import sys
import os
import re
import glob

SKIP_NAMES = {'shared.go', 'share.go'}


def skip_string(content, i):
    quote = content[i]
    i += 1
    while i < len(content):
        if content[i] == '\\':
            i += 2
        elif content[i] == quote:
            return i + 1
        else:
            i += 1
    return i


def skip_raw_string(content, i):
    i += 1  # skip opening backtick
    while i < len(content):
        if content[i] == '`':
            return i + 1
        i += 1
    return i


def skip_line_comment(content, i):
    while i < len(content) and content[i] != '\n':
        i += 1
    return i


def skip_block_comment(content, i):
    i += 2
    while i < len(content) - 1:
        if content[i] == '*' and content[i + 1] == '/':
            return i + 2
        i += 1
    return i


def advance(content, i):
    """If position i starts a string or comment, return the index past it. Otherwise return None."""
    if content[i] in ('"', "'"):
        return skip_string(content, i)
    if content[i] == '`':
        return skip_raw_string(content, i)
    if content[i:i + 2] == '//':
        return skip_line_comment(content, i)
    if content[i:i + 2] == '/*':
        return skip_block_comment(content, i)
    return None


def find_function_bodies(content):
    """Return list of (brace_start, brace_end) positions for each function body."""
    bodies = []
    i = 0
    n = len(content)

    while i < n:
        new_i = advance(content, i)
        if new_i is not None:
            i = new_i
            continue

        # Match 'func ' at the start of a line
        if (i == 0 or content[i - 1] == '\n') and content[i:i + 5] == 'func ':
            j = i + 5
            paren_depth = 0
            brace_start = -1

            while j < n:
                new_j = advance(content, j)
                if new_j is not None:
                    j = new_j
                    continue
                ch = content[j]
                if ch == '(':
                    paren_depth += 1
                elif ch == ')':
                    paren_depth -= 1
                elif ch == '{' and paren_depth == 0:
                    brace_start = j
                    break
                j += 1

            if brace_start == -1:
                i += 1
                continue

            # Find the matching closing brace
            depth = 1
            k = brace_start + 1
            while k < n and depth > 0:
                new_k = advance(content, k)
                if new_k is not None:
                    k = new_k
                    continue
                ch = content[k]
                if ch == '{':
                    depth += 1
                elif ch == '}':
                    depth -= 1
                k += 1

            brace_end = k - 1
            bodies.append((brace_start, brace_end))
            i = brace_end + 1
        else:
            i += 1

    return bodies


def remove_imports(content):
    """Remove all import declarations (they'll be unused after stubbing)."""
    content = re.sub(r'\nimport\s+"[^"]*"\n', '\n', content)
    content = re.sub(r'\nimport\s+\([^)]*\)\n', '\n', content, flags=re.DOTALL)
    return content


def stub_file(filepath):
    with open(filepath, 'r') as f:
        content = f.read()

    bodies = find_function_bodies(content)
    if not bodies:
        print(f"  No functions found in {os.path.basename(filepath)}, skipping")
        return

    stub_body = '\n\t// :TODO\n\tpanic("TODO")\n'

    result = content
    for brace_start, brace_end in reversed(bodies):
        result = result[:brace_start + 1] + stub_body + result[brace_end:]

    result = remove_imports(result)
    result = re.sub(r'\n{3,}', '\n\n', result)

    with open(filepath, 'w') as f:
        f.write(result)

    fn_word = "function" if len(bodies) == 1 else "functions"
    print(f"  Stubbed {len(bodies)} {fn_word} in {os.path.basename(filepath)}")


def main():
    if len(sys.argv) < 2:
        print("Usage: stub_functions.py <folder>")
        sys.exit(1)

    folder = sys.argv[1]

    if not os.path.isdir(folder):
        print(f"Error: directory '{folder}' not found")
        sys.exit(1)

    go_files = sorted(glob.glob(os.path.join(folder, '*.go')))
    solution_files = [
        f for f in go_files
        if not os.path.basename(f).endswith('_test.go')
        and os.path.basename(f) not in SKIP_NAMES
    ]

    if not solution_files:
        print(f"No solution files found in '{folder}'")
        sys.exit(1)

    print(f"Stubbing {len(solution_files)} file(s) in '{folder}'...")
    for f in solution_files:
        stub_file(f)
    print("Done! Use 'git diff' to review and 'git checkout -- <folder>' to restore.")


if __name__ == '__main__':
    main()
