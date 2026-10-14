# DSA Patterns — Rust

Rust implementations of the DSA patterns. Each pattern has its own module with clean, self-contained implementations and table-driven unit tests.

The problems, comments, and test cases mirror the [Go implementation](../go/): each Go file has a Rust file of the same name (`slidingwindow/avg.go` → `slidingwindow/avg.rs`), with function names in `snake_case`.

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

**Requirements:** a recent stable Rust (written against 1.94), with the `rustfmt` and `clippy` components that `rustup` installs by default

All commands run from this directory (`rust/`):

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

## Project Structure

Everything is a single crate (`Cargo.toml`), with `lib.rs` listing one module per pattern. Each pattern lives in its own folder. Every problem has:
- An implementation file with a comment describing the problem, examples, and constraints
- A paired `_test.rs` file with table-driven tests

```
rust/
├── Cargo.toml
├── lib.rs                 # one `pub mod` line per pattern
├── scripts/               # practice mode
├── slidingwindow/
│   ├── mod.rs             # lists the files in this pattern
│   ├── shared.rs          # shared types and helpers
│   ├── avg.rs             # problem implementation
│   ├── avg_test.rs        # table-driven tests
│   └── ...
└── ...
```

Rust only compiles files that are declared as modules, so a new file needs a line before its tests will run.

**Adding a problem** to an existing pattern: add two lines to that pattern's `mod.rs`:

```rust
pub mod maximumsub;

#[cfg(test)]
mod maximumsub_test;
```

**Adding a pattern:** create the folder with a `mod.rs`, and add `pub mod <folder>;` to `lib.rs`.

Solution functions are `pub` so the compiler doesn't report them as unused; test files reach them with `use super::avg::find_averages;`.

### How the Go code maps to Rust

| Go | Rust here |
|---|---|
| `[]int` parameter | `&[i32]`, or `&mut [i32]` when the function changes it in place |
| `[]int` result | `Vec<i32>` |
| lengths, counts, indices | `usize` |
| `string` | `&str` in, `String` out; indexed as bytes with `.as_bytes()` |
| `map[K]V`, a map used as a set | `HashMap<K, V>`, `HashSet<K>` |
| a sorted map | `BTreeMap<K, V>` |
| `container/heap` | `BinaryHeap`, a max heap; `Reverse(x)` turns it into a min heap |
| a slice used as a queue | `VecDeque` |
| a slice used as a stack | `Vec` (`push`, `pop`, `last`) |
| `*ListNode`, `*TreeNode` | `Option<Box<Node>>` |
| "return -1 if there is none" | `-1` where the problem statement asks for it, otherwise `Option` |

`Box` allows a node only one owner. Two patterns need more than that, so their nodes are `Option<Rc<RefCell<Node>>>` instead: [Fast & Slow Pointers](./fastandslowpointers/), where a list can loop back on itself, and [Tree BFS](./treebfs/), where nodes also point at their neighbour. Each `shared.rs` explains the type it uses.

A few searches step one position past the start of an array (`end = mid - 1`, or a neighbouring cell at row `-1`). A `usize` can't go below zero, so those use `i32` indices and cast where they index.

### Test data

Each test is a table of tuples, one per case, with the name first. Linked lists are built from a slice with `build_list(&[1, 2, 3])` and trees from their values in level order with `tree("[1, 2, null, 3]")`; both helpers live in the pattern's `shared.rs`.

## Formatting

`make fmt` runs `rustfmt`, which wraps code at 80 columns (`rustfmt.toml`). It leaves comments alone, so `make lint` also fails on any line over 80 characters.

## Practice Mode

To practice a pattern from scratch, use the `practice` script (run from this directory) to strip all function bodies and replace them with a `// TODO` stub that still compiles:

```sh
./scripts/practice.sh <folder>
```

**Example:**

```sh
./scripts/practice.sh slidingwindow
```

This replaces every solution function body with a `// TODO:` comment and a `todo!()` that compiles. For example:

```rust
pub fn find_averages(k: usize, arr: &[i32]) -> Vec<f64> {
    // TODO:
    todo!()
}
```

All tests still run and each unimplemented function shows a clear failure (`not yet implemented`, with the file and line of the stub). Fix one function at a time and re-run tests to see your progress.

Each stubbed file also gets `#![allow(unused, clippy::all)]` as its first line, so the compiler doesn't warn about the parameters and imports the stubs no longer use. Delete that line once the file is written to get the warnings back.

When you're done (or want to check your work), restore the originals with git:

```sh
git checkout -- slidingwindow/
```

> `shared.rs`, `mod.rs`, and `*_test.rs` files are never modified.

## Debugging

A single problem can be stepped through with `lldb`:

```sh
make debug T=topkelements/ksmallest
```

This builds the tests and opens that problem's test in `rust-lldb`, which is `lldb` set up to print Rust types such as slices, `Vec`, and `String` readably. It comes with `rustup`; `lldb` itself has to be installed separately.

Set breakpoints, then start the program:

```
(lldb) b find_kth_smallest_number
(lldb) b ksmallest.rs:32
(lldb) run
```

The commands you'll use most:

| Command | What it does |
|---|---|
| `b find_kth_smallest_number` | Break when a function is called |
| `b ksmallest.rs:32` | Break at a file and line |
| `breakpoint modify -c "k == 4" 2` | Make breakpoint 2 stop only when a condition is true |
| `breakpoint list` / `breakpoint delete 2` | List breakpoints / remove one |
| `run` | Start the program |
| `c` | Continue to the next breakpoint |
| `n` / `s` / `finish` | Step over a line / step into a function / step out of it |
| `frame variable` | Print all the local variables |
| `p k`, `p nums` | Print a variable |
| `watchpoint set variable k` | Stop whenever a variable changes |
| `bt` | Print the stack trace |
| `up` / `down` | Move to the caller's frame and back |
| `q` | Quit |

Two things specific to this project:

- **A variable only exists after its `let` line has run.** Stopped on `let mut max_heap = ...`, `p max_heap` reports an undeclared identifier; step over the line with `n` first.
- **Which test case am I in?** Every row of a test table calls the same code. Type `up` to move into the test function and `p name` to print the name of the row, then `down` to go back.

## Makefile Targets

| Target | Description |
|---|---|
| `make build` | Compile the crate |
| `make test` | Run all tests |
| `make test-verbose` | Run tests with verbose output |
| `make debug T=<folder>/<problem>` | Build the tests and open one in `rust-lldb` |
| `make fmt` | Format with `rustfmt` (wraps code at 80 characters) |
| `make fmt-check` | Fail if any file is not formatted |
| `make lint` | Run `clippy` with warnings as errors; fail on lines over 80 characters |
| `make check` | Run lint + tests + fmt |
| `make clean` | Remove build artifacts |

Add `P=<folder>` to `test` or `test-verbose` to limit it to one pattern. The folder is matched against the end of the module name, so `P=stack` also runs `monotonicstack`.
