# DSA Patterns — Rust

Rust implementations of the DSA patterns. Each pattern has its own module with clean, self-contained implementations and table-driven unit tests.

The problems, comments, and test cases mirror the [Go implementation](../go/): each Go file has a Rust file of the same name (`slidingwindow/avg.go` → `slidingwindow/avg.rs`), with function names in `snake_case`.

## Patterns

| Pattern | Problems |
|---|---|
| [Sliding Window](./slidingwindow/) | 1 |

## Getting Started

**Requirements:** Rust 1.85+ (`cargo`, with the `rustfmt` and `clippy` components)

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

## Makefile Targets

| Target | Description |
|---|---|
| `make build` | Compile the crate |
| `make test` | Run all tests |
| `make test-verbose` | Run tests with verbose output |
| `make fmt` | Format with `rustfmt` (wraps code at 80 characters) |
| `make fmt-check` | Fail if any file is not formatted |
| `make lint` | Run `clippy` with warnings as errors; fail on lines over 80 characters |
| `make check` | Run lint + tests + fmt |
| `make clean` | Remove build artifacts |

Add `P=<folder>` to `test` or `test-verbose` to limit it to one pattern.
