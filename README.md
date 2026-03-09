# DSA Patterns

A structured collection of data structures and algorithm problems solved in Go, organized by algorithmic pattern. Each pattern has its own package with clean, self-contained implementations and table-driven unit tests.

## Patterns

| Pattern | Problems |
|---|---|
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
| [Modified Binary Search](./modifiedbinarysearch/) | 3 |
| [Stack](./stack/) | 6 |

## Getting Started

**Requirements:** Go 1.23.4+

```sh
# Run all tests
make test

# Run tests with verbose output
make test-verbose

# Run vet + lint + tests (full quality gate)
make check
```

## Project Structure

Each pattern lives in its own package. Every problem has:
- An implementation file with a doc comment describing the problem, examples, and constraints
- A paired `_test.go` file with table-driven tests

```
dsapatterns/
├── slidingwindow/
│   ├── shared.go          # shared types and helpers
│   ├── avg.go             # problem implementation
│   ├── avg_test.go        # table-driven tests
│   └── ...
├── twopointers/
└── ...
```

## Makefile Targets

| Target | Description |
|---|---|
| `make build` | Compile all packages |
| `make test` | Run all tests |
| `make test-verbose` | Run tests with verbose output |
| `make vet` | Run `go vet` |
| `make fmt` | Run `gofmt` |
| `make lint` | Run `golangci-lint` |
| `make check` | Run vet + lint + tests |
| `make clean` | Remove build artifacts |
