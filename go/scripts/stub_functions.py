#!/usr/bin/env python3
"""
Replaces function bodies in Go solution files with a
// TODO + zero-value return stub.
Tests will compile and run, showing failures for each
unimplemented function individually.

Skips:
  - *_test.go files
  - shared.go / share.go (infrastructure helpers)
  - Methods named Len, Less, Swap, Push, Pop (heap/sort interface boilerplate)

Usage: stub_functions.py <folder>
"""

import sys
import os
import re
import glob

SKIP_NAMES = {'shared.go', 'share.go'}

# Heap/sort interface methods — stubbing these breaks infrastructure
BOILERPLATE_METHODS = {'Len', 'Less', 'Swap', 'Push', 'Pop'}

NUMERIC_TYPES = {
    'int', 'int8', 'int16', 'int32', 'int64',
    'uint', 'uint8', 'uint16', 'uint32', 'uint64',
    'byte', 'rune', 'float32', 'float64',
    'complex64', 'complex128', 'uintptr',
}

NON_STRUCT_NAMES = {'bool', 'string', 'error', 'any'} | NUMERIC_TYPES


# ---------------------------------------------------------------------------
# Lexer helpers
# ---------------------------------------------------------------------------

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
    i += 1
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
    """Return index past any string/comment starting at i,
    or None if not applicable."""
    if content[i] in ('"', "'"):
        return skip_string(content, i)
    if content[i] == '`':
        return skip_raw_string(content, i)
    if content[i:i + 2] == '//':
        return skip_line_comment(content, i)
    if content[i:i + 2] == '/*':
        return skip_block_comment(content, i)
    return None


# ---------------------------------------------------------------------------
# Signature parsing
# ---------------------------------------------------------------------------

def extract_func_info(sig):
    """Return (name, has_receiver, return_type_str) from a
    func signature string."""
    s = sig[5:]  # strip leading 'func '

    has_receiver = False
    s = s.lstrip()
    if s.startswith('('):
        has_receiver = True
        depth, i = 1, 1
        while i < len(s) and depth > 0:
            if s[i] == '(':
                depth += 1
            elif s[i] == ')':
                depth -= 1
            i += 1
        s = s[i:].lstrip()

    # Function name: up to '('
    m = re.match(r'^([A-Za-z_][A-Za-z0-9_]*)', s)
    name = m.group(1) if m else ''
    s = s[len(name):].lstrip()

    # Skip parameter list
    if s.startswith('('):
        depth, i = 1, 1
        while i < len(s) and depth > 0:
            if s[i] == '(':
                depth += 1
            elif s[i] == ')':
                depth -= 1
            i += 1
        s = s[i:].strip()

    return name, has_receiver, s  # s is the return type string


def strip_param_name(t):
    """'result bool' -> 'bool', '[]int' -> '[]int'."""
    parts = t.split(None, 1)
    if len(parts) == 2:
        first = parts[0]
        if (re.match(r'^[a-zA-Z_][a-zA-Z0-9_]*$', first)
                and first not in NON_STRUCT_NAMES):
            return parts[1]
    return t


def split_return_types(return_str):
    """Parse a return type string into a list of bare type strings."""
    r = return_str.strip()
    if not r:
        return []

    if r.startswith('(') and r.endswith(')'):
        inner = r[1:-1].strip()
        parts, depth, cur = [], 0, ''
        for ch in inner:
            if ch in '([{':
                depth += 1
            elif ch in ')]}':
                depth -= 1
            elif ch == ',' and depth == 0:
                parts.append(cur.strip())
                cur = ''
                continue
            cur += ch
        if cur.strip():
            parts.append(cur.strip())
        return [strip_param_name(p) for p in parts]

    return [r]


def zero_value_for(type_str):
    t = type_str.strip()
    if t == 'bool':
        return 'false'
    if t == 'string':
        return '""'
    if t in NUMERIC_TYPES:
        return '0'
    if (t in ('error', 'any')
            or t.startswith('*')
            or t.startswith('[]')
            or t.startswith('map[')
            or t.startswith('chan ')
            or t.startswith('interface')):
        return 'nil'
    # Named type — assume struct
    return t + '{}'


def make_stub_body(return_str):
    types = split_return_types(return_str)
    if not types:
        return '\n\t// TODO:\n'
    zeros = ', '.join(zero_value_for(t) for t in types)
    return f'\n\t// TODO:\n\treturn {zeros}\n'


# ---------------------------------------------------------------------------
# AST-lite: find function bodies
# ---------------------------------------------------------------------------

def find_functions(content):
    """Yield (func_start, brace_start, brace_end) for each
    function in content."""
    i, n = 0, len(content)

    while i < n:
        new_i = advance(content, i)
        if new_i is not None:
            i = new_i
            continue

        if (i == 0 or content[i - 1] == '\n') and content[i:i + 5] == 'func ':
            func_start = i
            j = i + 5
            paren_depth, brace_start = 0, -1

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

            depth, k = 1, brace_start + 1
            while k < n and depth > 0:
                new_k = advance(content, k)
                if new_k is not None:
                    k = new_k
                    continue
                if content[k] == '{':
                    depth += 1
                elif content[k] == '}':
                    depth -= 1
                k += 1

            brace_end = k - 1
            yield func_start, brace_start, brace_end
            i = brace_end + 1
        else:
            i += 1


# ---------------------------------------------------------------------------
# Import removal
# ---------------------------------------------------------------------------

def remove_imports(content):
    content = re.sub(r'\nimport\s+"[^"]*"\n', '\n', content)
    content = re.sub(r'\nimport\s+\([^)]*\)\n', '\n', content, flags=re.DOTALL)
    return content


# ---------------------------------------------------------------------------
# File processing
# ---------------------------------------------------------------------------

def stub_file(filepath):
    with open(filepath, 'r') as f:
        content = f.read()

    funcs = list(find_functions(content))
    if not funcs:
        print(
            f"  No functions found in "
            f"{os.path.basename(filepath)}, skipping"
        )
        return

    stubs = []
    skipped = 0
    for func_start, brace_start, brace_end in funcs:
        sig = content[func_start:brace_start]
        name, has_receiver, return_str = extract_func_info(sig)

        if has_receiver and name in BOILERPLATE_METHODS:
            skipped += 1
            continue

        stubs.append((brace_start, brace_end, make_stub_body(return_str)))

    if not stubs:
        print(
            f"  Only boilerplate methods in "
            f"{os.path.basename(filepath)}, skipping"
        )
        return

    result = content
    for brace_start, brace_end, stub_body in reversed(stubs):
        result = result[:brace_start + 1] + stub_body + result[brace_end:]

    result = remove_imports(result)
    result = re.sub(r'\n{3,}', '\n\n', result)

    with open(filepath, 'w') as f:
        f.write(result)

    fn_word = "function" if len(stubs) == 1 else "functions"
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
    print(
        "Done! Use 'git diff' to review and "
        "'git checkout -- <folder>' to restore."
    )


if __name__ == '__main__':
    main()
