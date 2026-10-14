#!/usr/bin/env python3
"""Replaces every function body in a pattern folder with a TODO stub.

Usage: stub_functions.py <folder>

Free functions and the methods of classes are stubbed; a docstring at the
top of a function is kept. shared.py, __init__.py and *_test.py files are
left alone. Running it again on stubbed files changes nothing.
"""

import ast
import sys
import tokenize
from pathlib import Path

STUB = ["# TODO:", "raise NotImplementedError"]
SKIP = {"shared.py", "__init__.py"}


def outer_functions(
    body: list[ast.stmt],
) -> list[ast.FunctionDef | ast.AsyncFunctionDef]:
    """Returns the functions in body and in its classes, but not functions
    nested inside other functions, which go away with their parent's body."""
    found: list[ast.FunctionDef | ast.AsyncFunctionDef] = []
    for node in body:
        if isinstance(node, ast.FunctionDef | ast.AsyncFunctionDef):
            found.append(node)
        elif isinstance(node, ast.ClassDef):
            found.extend(outer_functions(node.body))
    return found


def header_colon(
    tokens: list[tokenize.TokenInfo], func: ast.stmt
) -> tuple[int, int]:
    """Returns the (line, column) of the ':' that ends the def line."""
    depth = 0
    started = False
    for tok in tokens:
        if tok.start[0] < func.lineno:
            continue
        if not started:
            started = tok.type == tokenize.NAME and tok.string == "def"
            continue
        if tok.type != tokenize.OP:
            continue
        if tok.string in "([{":
            depth += 1
        elif tok.string in ")]}":
            depth -= 1
        elif tok.string == ":" and depth == 0:
            return tok.start
    raise ValueError(f"no ':' after def on line {func.lineno}")


def is_stub(func: ast.FunctionDef | ast.AsyncFunctionDef) -> bool:
    body = func.body
    if ast.get_docstring(func) is not None:
        body = body[1:]
    return (
        len(body) == 1 and ast.unparse(body[0]) == "raise NotImplementedError"
    )


def stub_file(path: Path) -> bool:
    source = path.read_text()
    tree = ast.parse(source)
    with path.open("rb") as f:
        tokens = list(tokenize.tokenize(f.readline))
    lines = source.splitlines(keepends=True)

    funcs = [f for f in outer_functions(tree.body) if not is_stub(f)]
    # work from the bottom up so earlier line numbers stay valid
    for func in sorted(funcs, key=lambda f: f.lineno, reverse=True):
        end = func.end_lineno or func.lineno
        has_docstring = ast.get_docstring(func) is not None
        first = func.body[0]
        indent = " " * first.col_offset
        stub = [indent + line + "\n" for line in STUB]

        if has_docstring:
            # keep the docstring; replace everything after it
            start = (first.end_lineno or first.lineno) + 1
        else:
            colon_line, colon_col = header_colon(tokens, func)
            if first.lineno == colon_line:
                # one-line function: `def f(): return 1`
                head = lines[colon_line - 1][: colon_col + 1].rstrip()
                indent = " " * (func.col_offset + 4)
                stub = [indent + line + "\n" for line in STUB]
                lines[colon_line - 1 : end] = [head + "\n", *stub]
                continue
            start = colon_line + 1
        lines[start - 1 : end] = stub

    if not funcs:
        return False
    path.write_text("".join(lines))
    return True


def main() -> int:
    if len(sys.argv) != 2:
        print("Usage: stub_functions.py <folder>", file=sys.stderr)
        return 1
    folder = Path(sys.argv[1])
    if not folder.is_dir():
        print(f"Error: {folder} is not a directory", file=sys.stderr)
        return 1

    changed = 0
    for path in sorted(folder.glob("*.py")):
        if path.name in SKIP or path.name.endswith("_test.py"):
            continue
        if stub_file(path):
            print(f"Stubbed: {path}")
            changed += 1
    print(f"Done. {changed} file(s) stubbed.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
