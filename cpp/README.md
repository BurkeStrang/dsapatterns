# DSA Patterns — C++

C++ implementations of the DSA patterns. Each pattern has its own folder with clean, self-contained implementations and table-driven unit tests.

The problems, comments, and test cases mirror the [Go implementation](../go/): each Go file has a C++ file of the same name (`slidingwindow/avg.go` → `slidingwindow/avg.cpp`), with function names in `snake_case`. The test tables follow the [Rust folder](../rust/), which added cases and fixed a few Go tests that could never fail.

A few file names differ from Go: names are all lowercase (`stack/balancedparentheses.cpp`, `stack/reversestring.cpp`, `monotonicstack/removeadjactentdupsii.cpp`), and `knapsackdp/01knapsack.go` is `knapsackdp/knapsack01.cpp`, matching the Rust folder.

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

**Requirements:** a C++20 compiler (`clang++` by default, `g++` 13 or later also works), `make`, `python3` (`make fmt` uses it to install the pinned `clang-format`), and `lldb` for debugging

All commands run from this directory (`cpp/`):

```sh
# Run all tests
make test

# Run the tests for one pattern
make test P=slidingwindow

# Run tests with verbose output
make test-verbose

# Run lint + tests + fmt (full quality gate)
make check

# Build with g++ instead of clang++
make test CXX=g++
```

Tests are built with the address and undefined-behaviour sanitizers, so out-of-bounds reads, leaks, and similar mistakes fail the test instead of passing silently. (`vector::operator[]` does no bounds check of its own; the sanitizer is what catches it.)

Each test program takes a second or two to compile, so the first `make test` builds everything on all cores at once and still takes a few minutes. After that only the tests whose files changed are rebuilt, and `make test P=<folder>` builds just one pattern.

## Project Structure

Each pattern lives in its own folder. Every problem has:
- An implementation file with a comment describing the problem, examples, and constraints
- A paired `_test.cpp` file with table-driven tests

```
cpp/
├── testing/
│   └── testing.hpp        # test helpers (t::run, t::check, t::errorf, t::done)
├── common/
│   ├── list.hpp           # ListNode, build_list, list_values
│   └── tree.hpp           # TreeNode, tree("[1, 2, null, 3]")
├── slidingwindow/
│   ├── avg.cpp            # problem implementation
│   ├── avg_test.cpp       # table-driven tests
│   └── ...
└── ...
```

As in the [C folder](../c/), there are no per-problem header files. Each `_test.cpp` file includes its solution directly (`#include "avg.cpp"`) and has its own `main`, so every test file builds into a separate program under `build/`. That keeps one problem's names from clashing with another's, and a crash in one test can't take the others down. Helpers shared by a pattern go in that folder's `shared.hpp`.

There is no test framework to install: `testing/testing.hpp` is a small header written for this repo.

### Adding a problem

1. Write `<pattern>/<problem>.cpp` with the problem comment from the Go file and the solution as a free function.
2. Write `<pattern>/<problem>_test.cpp`: include the solution, then `testing/testing.hpp`, and loop over a table of cases:

```cpp
#include "avg.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        int k;
        std::vector<int> arr;
        std::vector<double> want;
    };
    std::vector<test> tests = {
        {"window size 1", 1, {5, 10, 15}, {5.0, 10.0, 15.0}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<double> got = find_averages(tt.k, tt.arr);
        t::check_near("find_averages()", got, tt.want);
    }
    return t::done();
}
```

The Makefile finds every `*_test.cpp`, so nothing needs registering.

### Linked lists and trees

`common/list.hpp` and `common/tree.hpp` hold the node types for every list and tree pattern. Nodes are plain pointers, as in the Go code, so a solution can relink nodes, build a cycle, or point a tree node at its neighbour with `next` without any ownership rules getting in the way.

Nodes are made with `new_node(value)` and `new_tree_node(value)`, which keep every node in a pool that lives until the program exits. Nothing is ever deleted, which is what lets the pointers be shared freely, and the leak checker stays quiet because the pool still holds every node.

Tests build their inputs from short text: `build_list({1, 2, 3})` for a list and `tree("[1, 2, null, 3]")` for a tree in level order, with `null` for a missing child. `list_values(head)` turns a list back into a vector to compare.

### Trie

Go adds the trie's methods in several files of the pattern. A C++ class can't be spread over files, so `trie/shared.hpp` holds only the node type, and each problem defines the trie class it needs (`Trie` with `insert`, `search` and `starts_with` in `prefixtrie.cpp`, with `add_word` and `search_node` in `searchadd.cpp`, and so on).

### How the Go code maps to C++

| Go | C++ |
|---|---|
| `[]int`, `[][]int` | `std::vector<int>`, `std::vector<std::vector<int>>` |
| `map[K]V` | `std::unordered_map<K, V>` (`std::map` where order matters) |
| `container/heap` | `std::priority_queue` (a max heap; pass `std::greater<>` for a min heap) |
| a slice used as a queue | `std::queue` or `std::deque` |
| `strings.Builder` | `std::string` with `+=` |
| `sort.Ints`, `sort.Slice` | `std::ranges::sort` |
| `-1` for "not found" | kept where the problem asks for it, otherwise `std::optional` |
| `[]int` holding a fixed pair, e.g. an edge | `std::array<int, 2>` |
| `int` sizes and indices | `int`, using `std::ssize(v)` for a signed size |

Inputs the function only reads are taken by `const &`; inputs the problem changes in place are taken by `&`.

### Test helpers

| Helper | What it does |
|---|---|
| `t::run(name)` | Start a test case; failures after it are reported under its name |
| `t::check(label, got, want)` | Fail if `got != want`, printing both, e.g. `f() = [1, 2], want [2, 1]` |
| `t::check_near(label, got, want)` | The same for a `double` or `std::vector<double>`, allowing a difference under 1e-9 |
| `t::errorf("got {} want {}", a, b)` | Report any other failure, with `std::format` placeholders |
| `t::done()` | Print the summary; return it from `main` |

Failure messages print numbers, strings, `std::vector`, `std::optional` and `std::pair`, nested to any depth.

## Formatting

`make fmt` formats every `.cpp` and `.hpp` file with `clang-format`, using `.clang-format` (Allman braces, 4 spaces, 80 columns). `make fmt-check` reports files that are not formatted without changing them.

`clang-format` is pinned to version 18.1.3, because each release formats a little differently and CI would fail on whichever version the runner happens to have. You don't need to install it: the first `make fmt` or `make fmt-check` installs that version from PyPI into `.tools/` (ignored by git), which needs `python3`. To upgrade, change `CLANG_FORMAT_VERSION` in the Makefile and run `make fmt`.

Unlike the C folder, there is no extra step after `clang-format`, so an editor's format-on-save gives the same result as `make fmt`, as long as the editor uses the same version: point its `clang-format` path at `.tools/bin/clang-format`, or run `make fmt` before committing.

## Practice Mode

To practice a pattern from scratch, use the `practice` script (run from this directory) to strip all function bodies and replace them with a `// TODO` stub that still compiles:

```sh
./scripts/practice.sh <folder>
```

**Example:**

```sh
./scripts/practice.sh slidingwindow
```

This replaces every function body (free functions and the member functions of structs and classes) with a `// TODO:` comment and `return {};`, which compiles for any return type except `void`, where it is left out:

```cpp
std::vector<double> find_averages(int k, const std::vector<int> &arr)
{
    // TODO:
    return {};
}
```

All tests still run and each unimplemented function shows a clear failure (`find_averages() = [], want [5]`) per test case. Fix one function at a time and re-run tests to see your progress.

When you're done (or want to check your work), restore the originals with git:

```sh
git checkout -- slidingwindow/
```

> `shared.cpp` / `shared.hpp` files and `*_test.cpp` files are never modified.

While practicing, `make lint` fails on the stubs' unused parameters; `make test` does not.

## Debugging

Every test file builds into its own program with debug information, so a single problem can be stepped through with `lldb`:

```sh
make debug T=slidingwindow/avg
```

This builds that test if needed and opens it in `lldb`. Use `make debug` rather than running `lldb build/..._test` directly: the tests are built with leak detection, which can't run under a debugger and takes `lldb` down with it when the program finishes, so the target switches it off.

The folder builds with `clang++` by default because `lldb` reads its debug information best. A build made with `make CXX=g++` still works, but a breakpoint on a function can stop inside an inlined standard library call first.

Set breakpoints, then start the program:

```
(lldb) b find_averages
(lldb) b avg.cpp:20
(lldb) run
```

The commands you'll use most:

| Command | What it does |
|---|---|
| `b find_averages` | Break when a function is called |
| `b avg.cpp:20` | Break at a file and line |
| `breakpoint modify -c "window_end == 4" 2` | Make breakpoint 2 stop only when a condition is true |
| `breakpoint list` / `breakpoint delete 2` | List breakpoints / remove one |
| `run` | Start the program |
| `c` | Continue to the next breakpoint |
| `n` / `s` / `finish` | Step over a line / step into a function / step out of it |
| `frame variable` | Print all the local variables |
| `p k`, `p arr`, `p arr[2]` | Print a variable or any expression; vectors print their size and every element |
| `display window_sum` / `undisplay 1` | Print an expression after every step / stop doing so |
| `watchpoint set variable window_sum` | Stop whenever a variable changes |
| `bt` | Print the stack trace |
| `up` / `down` | Move to the caller's frame and back |
| `q` | Quit |

Two things specific to this project:

- **Which test case am I in?** Every row of a test table calls the same code. Type `up` to move into the test's `main` and `p tt.name` (or `p tt` for the whole row), then `down` to go back.
- **Stopping in one test case only.** Put a conditional breakpoint on the line of the test that calls the solution. `lldb` can't call `std::string`'s `==`, so compare with `strcmp`:

  ```
  (lldb) breakpoint set -f avg_test.cpp -l 26 -c '(int)strcmp(tt.name.c_str(), "window size 1") == 0'
  ```

## Editor Support (clangd)

`clangd` needs a `compile_commands.json` file to know how each C++ file is compiled; without it the editor reports headers such as `testing/testing.hpp` as not found and C++20 features such as `std::format` as missing. The file is generated automatically:

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
| `make fmt` | Format with `clang-format` |
| `make fmt-check` | Fail if any file is not formatted |
| `make lint` | Compile with strict warnings as errors; fail on lines over 80 characters |
| `make check` | Run lint + tests + fmt |
| `make compile_commands.json` | Generate the file `clangd` reads for editor support |
| `make clean` | Remove build artifacts |

Add `P=<folder>` to `build`, `test`, `test-verbose`, or `lint` to limit it to one pattern, and `CXX=g++` to any target to use `g++`. The Makefile compiles on every core by default; add `-j1` to build one file at a time, for example to read a compile error without other output mixed in.
