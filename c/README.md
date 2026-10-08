# DSA Patterns — C

C implementations of the DSA patterns. Each pattern has its own folder with clean, self-contained implementations and table-driven unit tests.

The problems, comments, and test cases mirror the [Go implementation](../go/): each Go file has a C file of the same name (`slidingwindow/avg.go` → `slidingwindow/avg.c`), with function names in `snake_case`.

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
| [Topological Sort](./topologicalsort/) | 3 |
| [Miscellaneous](./misc/) | 3 |

## Getting Started

**Requirements:** a C17 compiler (`gcc` or `clang`), `make`, and `clang-format` for formatting

All commands run from this directory (`c/`):

```sh
# Run all tests
make test

# Run the tests for one pattern
make test P=slidingwindow

# Run tests with verbose output
make test-verbose

# Run lint + tests + fmt (full quality gate)
make check
```

Tests are built with the address and undefined-behaviour sanitizers, so out-of-bounds reads, leaks, and similar mistakes fail the test instead of passing silently.

## Project Structure

Each pattern lives in its own folder. Every problem has:
- An implementation file with a comment describing the problem, examples, and constraints
- A paired `_test.c` file with table-driven tests

```
c/
├── testing/
│   └── testing.h          # test helpers (t_run, t_check_int, t_errorf, t_done)
├── common/                # building blocks Go has built in (see below)
├── slidingwindow/
│   ├── shared.h           # shared types and helpers
│   ├── avg.c              # problem implementation
│   ├── avg_test.c         # table-driven tests
│   └── ...
└── ...
```

There are no per-problem header files. Each `_test.c` file includes its solution directly (`#include "avg.c"`) and has its own `main`, so every test file builds into a separate program under `build/`. That keeps one problem's function names from clashing with another's, and a crash in one test can't take the others down.

### Shared building blocks

C has no slices, maps, or heaps, so `common/` provides small header-only versions that the solutions use where the Go code uses the built-in ones:

| Header | Provides | Go equivalent |
|---|---|---|
| `common/list.h` | `IntList`, `IntMatrix`, `StrList` (growable lists) | `[]int`, `[][]int`, `[]string` with `append` |
| `common/map.h` | `IntMap`, `StrMap` (hash maps to `int`) | `map[int]int`, `map[string]int` |
| `common/heap.h` | `Heap` (priority queue with a custom order) | `container/heap` |
| `common/queue.h` | `Queue` (first in, first out) | a slice used as a queue |
| `common/strbuf.h` | `StrBuf` (growable string) | `strings.Builder` |
| `common/sort.h` | `sort_ints` | `sort.Ints` |

They are tested by `common/common_test.c`. Anything a solution returns in new memory (an array, a list, a string) is freed by its test; the tests run with leak detection on, so a missing `free` fails the test.

### Test data

Simple arrays are written in the test table with `INTS(1, 2, 3)` (and `STRS`, `DOUBLES`, `CHARS`). Lists of lists and trees are written as text and parsed, for example `"[[1, 2], [3]]"` for a matrix or `"[1, 2, null, 3]"` for a tree in level order.

## Formatting

`make fmt` formats every `.c` and `.h` file in two steps:

1. `clang-format`, using `.clang-format` (Allman braces, 4 spaces, 80 columns)
2. `scripts/format.py`, which puts each function's parameter list on its own lines, something `clang-format` has no setting for:

```c
int find_max_sum_sub_array
(
    int k,
    const int *arr,
    int arr_len
)
{
    ...
}
```

Functions that take no parameters keep `name(void)` on one line. `make fmt-check` reports files that are not formatted without changing them.

Because the second step is not part of `clang-format`, an editor's format-on-save (which only runs `clang-format`) will pull the parameters back onto one line; run `make fmt` afterwards, or turn format-on-save off for this folder.

## Practice Mode

To practice a pattern from scratch, use the `practice` script (run from this directory) to strip all function bodies and replace them with a `// TODO` stub that still compiles:

```sh
./scripts/practice.sh <folder>
```

**Example:**

```sh
./scripts/practice.sh slidingwindow
```

This replaces every solution function body with a `// TODO:` comment and a zero-value return that compiles. For example:

```c
double *find_averages
(
    int k,
    const int *arr,
    int arr_len,
    int *result_len
)
{
    // TODO:
    return NULL;
}
```

All tests still run and each unimplemented function shows a clear failure (`find_averages() = NULL, want [5]`) per test case. Fix one function at a time and re-run tests to see your progress.

When you're done (or want to check your work), restore the originals with git:

```sh
git checkout -- slidingwindow/
```

> `shared.h` / `shared.c` files and `*_test.c` files are never modified.

## Debugging

Every test file builds into its own program with debug information, so a single problem can be stepped through with `lldb`:

```sh
make debug T=topkelements/ksmallest
```

This builds that test if needed and opens it in `lldb`. Use `make debug` rather than running `lldb build/..._test` directly: the tests are built with leak detection, which can't run under a debugger and takes `lldb` down with it when the program finishes, so the target switches it off.

Set breakpoints, then start the program:

```
(lldb) b find_kth_smallest_number
(lldb) b ksmallest.c:44
(lldb) run
```

The commands you'll use most:

| Command | What it does |
|---|---|
| `b find_kth_smallest_number` | Break when a function is called |
| `b ksmallest.c:44` | Break at a file and line |
| `breakpoint modify -c "i == 4" 2` | Make breakpoint 2 stop only when a condition is true |
| `breakpoint list` / `breakpoint delete 2` | List breakpoints / remove one |
| `run` | Start the program |
| `c` | Continue to the next breakpoint |
| `n` / `s` / `finish` | Step over a line / step into a function / step out of it |
| `frame variable` | Print all the local variables |
| `p k`, `p nums[2]`, `p max_heap.len` | Print a variable or any expression |
| `parray 6 nums` | Print the first 6 elements of an array (a pointer alone only shows its address) |
| `p int_heap_top(&max_heap)` | Call a function and print the result |
| `display i` / `undisplay 1` | Print an expression after every step / stop doing so |
| `watchpoint set variable result` | Stop whenever a variable changes |
| `bt` | Print the stack trace |
| `up` / `down` | Move to the caller's frame and back |
| `q` | Quit |

Three things specific to this project:

- **Which test case am I in?** Every row of a test table calls the same code. Type `up` to move into the test's `main` and `p tt->name` (or `p *tt` for the whole row), then `down` to go back.
- **Stopping in one test case only.** Put a conditional breakpoint on the line of the test that calls the solution:

  ```
  (lldb) breakpoint set -f ksmallest_test.c -l 24 -c '(int)strcmp(tt->name, "Example 3") == 0'
  ```

- **Looking inside the shared types.** They hold their items behind a pointer, so print them with `parray` and a cast where needed:

  ```
  (lldb) parray 3 (int *)max_heap.items
  (lldb) parray `got.len` got.items
  ```

## Editor Support (clangd)

`clangd` needs a `compile_commands.json` file to know how each C file is compiled; without it the editor reports headers such as `testing/testing.h` as not found. The file is generated automatically:

- every `make build`, `make test`, and `make check` refreshes it, so new and deleted files are picked up
- `make compile_commands.json` creates it on its own, which is all a fresh clone needs

It holds absolute paths for this machine, so it is ignored by git. If the editor still shows stale errors after a new file is added, run `make compile_commands.json` and restart the language server.

## Makefile Targets

| Target | Description |
|---|---|
| `make build` | Compile all test programs |
| `make test` | Run all tests |
| `make test-verbose` | Run tests with verbose output |
| `make debug T=<folder>/<problem>` | Build one test and open it in `lldb` |
| `make fmt` | Format with `clang-format`, then put function parameters on their own lines |
| `make fmt-check` | Fail if any file is not formatted |
| `make lint` | Compile with strict warnings as errors; fail on lines over 80 characters |
| `make check` | Run lint + tests + fmt |
| `make compile_commands.json` | Generate the file `clangd` reads for editor support |
| `make clean` | Remove build artifacts |

Add `P=<folder>` to `build`, `test`, `test-verbose`, or `lint` to limit it to one pattern.
