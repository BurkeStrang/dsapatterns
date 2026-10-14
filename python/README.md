# DSA Patterns — Python

Python implementations of the DSA patterns. Each pattern has its own folder with clean, self-contained implementations and table-driven unit tests.

The problems, comments, and test cases mirror the [Go implementation](../go/): each Go file has a Python file of the same name (`slidingwindow/avg.go` → `slidingwindow/avg.py`), with function names in `snake_case`. The test tables follow the [Rust folder](../rust/), which added cases and fixed a few Go tests that could never fail.

A few file names differ from Go: names are all lowercase (`stack/balancedparentheses.py`, `stack/reversestring.py`, `monotonicstack/removeadjactentdupsii.py`), and `knapsackdp/01knapsack.go` is `knapsackdp/knapsack01.py`, because a Python module name can't start with a digit.

## Patterns

| Pattern | Problems |
|---|---|
| [Bitwise XOR](./bitwisexor/) | 5 |
| [Sliding Window](./slidingwindow/) | 13 |
| [Two Pointers](./twopointers/) | 10 |
| [Merge Intervals](./mergeintervals/) | 7 |
| [Cyclic Sort](./cyclicalsort/) | 8 |
| [Reverse Linked List](./reverselinkedlist/) | 5 |
| [Fast & Slow Pointers](./fastandslowpointers/) | 8 |
| [Graphs](./graphs/) | 5 |
| [Hash Maps](./hashmaps/) | 5 |
| [Island Traversal](./islandtraversal/) | 7 |
| [Level Order Traversal](./levelordertraversal/) | 7 |
| [Tree BFS](./treebfs/) | 7 |
| [Tree DFS](./treedfs/) | 7 |
| [Two Heaps](./twoheaps/) | 4 |
| [Subsets](./subsets/) | 8 |
| [Monotonic Stack](./monotonicstack/) | 7 |
| [Modified Binary Search](./modifiedbinarysearch/) | 11 |
| [Stack](./stack/) | 6 |
| [Top K Elements](./topkelements/) | 14 |
| [K-way Merge](./kwaymerge/) | 5 |
| [Greedy](./greedy/) | 6 |
| [0/1 Knapsack DP](./knapsackdp/) | 6 |
| [Fibonacci Numbers](./fibnum/) | 6 |
| [Palindromic Subsequence](./palindromicsubsequence/) | 5 |
| [Backtracking](./backtracking/) | 5 |
| [Trie](./trie/) | 5 |
| [Topological Sort](./topologicalsort/) | 7 |
| [Union Find](./unionfind/) | 4 |
| [Ordered Set](./orderedset/) | 1 |
| [Miscellaneous](./misc/) | 3 |

## Getting Started

**Requirements:** Python 3.12 or later and `make`. Everything else (pytest, ruff, mypy) is installed into a local `.venv` the first time any `make` target runs, at the versions pinned in `requirements-dev.txt`.

All commands run from this directory (`python/`):

```sh
# Run all tests
make test

# Run the tests for one pattern
make test P=slidingwindow

# Run one test case by name
make test P=slidingwindow CASE="window size 1"

# Run tests with verbose output
make test-verbose

# Run lint + tests + fmt (full quality gate)
make check
```

To run the tools by hand, use the copies in `.venv/bin` (`.venv/bin/pytest slidingwindow`), or activate the environment first with `source .venv/bin/activate`.

## Project Structure

Each pattern lives in its own folder. Every problem has:
- An implementation file whose docstring describes the problem, examples, and constraints
- A paired `_test.py` file with table-driven tests

```
python/
├── conftest.py            # adds pytest's --case option
├── common/
│   ├── list.py            # ListNode, build_list, list_values
│   └── tree.py            # TreeNode, tree([1, 2, None, 3])
├── pyproject.toml         # settings for pytest, ruff and mypy
├── requirements-dev.txt   # pinned tool versions
├── slidingwindow/
│   ├── __init__.py
│   ├── avg.py             # problem implementation
│   ├── avg_test.py        # table-driven tests
│   └── ...
└── ...
```

Each pattern folder is a package (it has an empty `__init__.py`), and tests import the solution by its full name: `from slidingwindow.avg import find_averages`. Helpers shared by a pattern go in that folder's `shared.py`.

### Adding a problem

1. Write `<pattern>/<problem>.py` with the problem comment from the Go file as the module docstring and the solution as a function with type hints.
2. Write `<pattern>/<problem>_test.py` with a table of cases. Each row is a `pytest.param` whose `id` is the case's name:

```python
import pytest

from slidingwindow.avg import find_averages


@pytest.mark.parametrize(
    ("k", "arr", "want"),
    [
        pytest.param(1, [5, 10, 15], [5.0, 10.0, 15.0], id="window size 1"),
    ],
)
def test_find_averages(k: int, arr: list[int], want: list[float]) -> None:
    assert find_averages(k, arr) == pytest.approx(want)
```

pytest finds every `*_test.py`, so nothing needs registering. A plain `assert` is all a test needs: when it fails, pytest prints both sides and where they differ. Use `pytest.approx` to compare floats.

If a new pattern folder is added, give it an empty `__init__.py`.

### Linked lists and trees

`common/list.py` and `common/tree.py` hold the node types for every list and tree pattern. Nodes are ordinary objects linked by reference, so a solution can relink nodes, build a cycle, or point a tree node at its neighbour with `next`, and Python's garbage collector cleans up after it.

Tests build their inputs from Python literals: `build_list([1, 2, 3])` for a list and `tree([1, 2, None, 3])` for a tree in level order, with `None` for a missing child. `list_values(head)` turns a list back into a Python list to compare. A test that needs a cycle uses `build_nodes`, which returns every node so the last one can be pointed back.

Because a node may be `None`, mypy makes the code check before following `.next`. Where the algorithm guarantees a node is there (the slow pointer always trails the fast one), the code says so with an `assert`, which also documents the reason.

### Trie

Go adds the trie's methods in several files of the pattern. Each Python problem defines the trie class it needs instead (`Trie` with `insert`, `search` and `starts_with` in `prefixtrie.py`, with `add_word` and `search_node` in `searchadd.py`, and so on), built from the shared `TrieNode` in `trie/shared.py`. A node keeps its children in a dict keyed by letter.

### How the Go code maps to Python

| Go | Python |
|---|---|
| `[]int`, `[][]int` | `list[int]`, `list[list[int]]` |
| `map[K]V` | `dict[K, V]`; `Counter` for counting and `defaultdict` for a default value |
| `container/heap` | `heapq`, a min heap over a plain list; a max heap stores negated numbers, which the comments point out |
| a slice used as a queue | `collections.deque` |
| a slice used as a stack | `list` with `append` and `pop` |
| `strings.Builder` | a `list[str]` joined with `"".join(...)` |
| `sort.Ints`, `sort.Slice` | `list.sort()` or `sorted()`, with `key=` |
| a struct | a `@dataclass`, which gives `==` and a readable `repr` for test failures |
| `-1` for "not found" | kept where the problem asks for it, otherwise `None` (`int \| None`) |
| `[]int` holding a fixed pair, e.g. an edge | `tuple[int, int]` |
| an out-parameter such as `*int` | a nested function that updates the outer variable with `nonlocal` |

Where the answer depends on how ties are broken (rearranging letters, k-largest pairs), the heaps use the same rule as the Rust and C++ folders, so the tests check exact answers.

## Lint and Formatting

| Tool | What it checks |
|---|---|
| `ruff check` | Likely bugs, unused imports and names, import order, PEP 8 naming, lines over 80 characters |
| `mypy` (strict) | Type hints: every function needs them, and the code must agree with them |
| `ruff format` | Formatting (80 columns, 4 spaces, double quotes) |

`make fmt` formats every file and sorts imports; `make fmt-check` reports files that are not formatted without changing them. The settings are in `pyproject.toml`.

## Practice Mode

To practice a pattern from scratch, use the `practice` script (run from this directory) to strip all function bodies and replace them with a stub:

```sh
./scripts/practice.sh <folder>
```

**Example:**

```sh
./scripts/practice.sh slidingwindow
```

This replaces every function body (free functions and the methods of classes) with a `# TODO:` comment and `raise NotImplementedError`. The problem docstring and any docstring on a function are kept:

```python
def find_averages(k: int, arr: list[int]) -> list[float]:
    # TODO:
    raise NotImplementedError
```

All tests still run and each test case fails with `NotImplementedError` until its function is written. Fix one function at a time and re-run tests to see your progress.

When you're done (or want to check your work), restore the originals with git:

```sh
git checkout -- slidingwindow/
```

> `shared.py`, `__init__.py`, and `*_test.py` files are never modified.

While practicing, `make lint` fails on imports the stubs no longer use; `make test` does not.

## Debugging

Python's debugger, `pdb`, comes with Python. To step through one problem:

```sh
make debug T=slidingwindow/avg CASE="window size 1"
```

This runs that problem's tests and stops in `pdb` at the start of the test case. Without `CASE` it stops at the start of every case in turn.

From there, set a breakpoint in the solution and continue to it:

```
(Pdb) b find_averages
(Pdb) c
```

The commands you'll use most:

| Command | What it does |
|---|---|
| `b find_averages` | Break when a function is called (it must be a name the current file can see, such as one the test imports) |
| `b slidingwindow/avg.py:16` | Break at a file and line |
| `b slidingwindow/avg.py:16, window_end == 2` | Break there only when a condition is true |
| `b` / `cl 2` | List breakpoints / remove breakpoint 2 |
| `c` | Continue to the next breakpoint |
| `n` / `s` / `r` | Step over a line / step into a function / run until the function returns |
| `p window_sum`, `p arr[2]` | Print a variable or any expression |
| `pp result` | Pretty-print a large value |
| `display window_sum` / `undisplay` | Print an expression whenever it changes after a step / stop doing so |
| `ll` | List the whole current function |
| `w` | Print the stack trace |
| `u` / `d` | Move to the caller's frame and back |
| `interact` | Open a Python shell with the current variables (Ctrl-D to return) |
| `q` | Quit |

You can also stop anywhere without `make debug`: put `breakpoint()` on a line in the solution and run `make test P=<folder>`. pytest switches off its output capture and opens `pdb` there. Remove the line when you're done.

**Which test case am I in?** Every row of a test table calls the same code. Type `u` until you reach `test_...` and `p k, arr, want` to see the row's inputs, then `d` to go back. With `CASE` set, only that row runs.

## Editor Support

Point the editor at the `.venv` interpreter (in VS Code, "Python: Select Interpreter" → `python/.venv/bin/python`) and it will find pytest for running and debugging tests, and the installed `ruff` and `mypy`. Open this folder (`python/`) as the workspace root so imports such as `from slidingwindow.avg import ...` resolve.

## Makefile Targets

| Target | Description |
|---|---|
| `make setup` | Create `.venv` and install the pinned tools (run automatically by every other target) |
| `make test` | Run all tests |
| `make test-verbose` | Run tests listing every test case |
| `make debug T=<folder>/<problem>` | Run one problem's tests under `pdb` |
| `make fmt` | Format with `ruff format` and sort imports |
| `make fmt-check` | Fail if any file is not formatted |
| `make lint` | Run `ruff check` and `mypy` |
| `make check` | Run lint + tests + fmt |
| `make clean` | Remove tool caches and `__pycache__` folders |

Add `P=<folder>` to `test` or `test-verbose` to limit it to one pattern, and `CASE="<name>"` to `test`, `test-verbose`, or `debug` to run only the test cases with that name. To start over with fresh tools, delete `.venv`.
