# DSA Patterns — TypeScript

TypeScript implementations of the DSA patterns. Each pattern has its own folder with clean, self-contained implementations and table-driven unit tests.

The problems, comments, and test cases mirror the [Go implementation](../go/): each Go file has a TypeScript file of the same name (`slidingwindow/avg.go` → `slidingwindow/avg.ts`), with the same function names (`findAverages`). The test tables follow the [Rust folder](../rust/), which added cases and fixed a few Go tests that could never fail.

A few file names differ from Go: names are all lowercase (`stack/balancedparentheses.ts`, `stack/reversestring.ts`, `monotonicstack/removeadjactentdupsii.ts`), and `knapsackdp/01knapsack.go` is `knapsackdp/knapsack01.ts`, matching the other folders.

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

**Requirements:** Node.js 24 or later (the version is in `.nvmrc`, so `nvm use` picks it) and `make`. Everything else (TypeScript, Vitest, ESLint, Prettier) is installed into `node_modules/` the first time any `make` target runs, at the exact versions in `package-lock.json`.

All commands run from this directory (`typescript/`):

```sh
# Run all tests
make test

# Run the tests for one pattern
make test P=slidingwindow

# Run the test cases whose name contains some text
make test P=slidingwindow CASE="window size 1"

# Run tests listing every test case
make test-verbose

# Run lint + tests + fmt (full quality gate)
make check
```

To run the tools by hand, use the copies in `node_modules/.bin` (`node_modules/.bin/vitest slidingwindow`), or `npx vitest slidingwindow`. Plain `vitest` without `run` stays open and reruns the tests whenever a file is saved.

## Project Structure

Each pattern lives in its own folder. Every problem has:
- An implementation file with a comment describing the problem, examples, and constraints
- A paired `.test.ts` file with table-driven tests (the usual TypeScript name, rather than the `_test` of the other folders)

```
typescript/
├── package.json           # the tools, pinned to exact versions
├── tsconfig.json          # type checking settings
├── eslint.config.js       # lint rules
├── vitest.config.ts       # where the tests are
├── common/
│   ├── heap.ts            # Heap, a priority queue
│   ├── list.ts            # ListNode, buildList, listValues
│   └── tree.ts            # TreeNode, tree([1, 2, null, 3])
├── slidingwindow/
│   ├── avg.ts             # problem implementation
│   ├── avg.test.ts        # table-driven tests
│   └── ...
└── ...
```

The code is ES modules, and imports name the `.ts` file itself (`import { findAverages } from "./avg.ts"`). Nothing is compiled to JavaScript: Vitest runs the `.ts` files directly, and `tsc` only checks the types. `tsconfig.json` also turns on `erasableSyntaxOnly`, which allows only TypeScript that Node can run by deleting the types, so no `enum`, `namespace`, or constructor parameter properties. A plain object with `as const` takes the place of an enum.

### Adding a problem

1. Write `<pattern>/<problem>.ts` with the problem comment from the Go file and the solution as an exported function.
2. Write `<pattern>/<problem>.test.ts` with a table of cases. `test.each` runs the test once per row, and `$name` puts the row's `name` into the test's title:

```ts
import { describe, expect, test } from "vitest";

import { findAverages } from "./avg.ts";

describe("findAverages", () => {
  test.each([
    { name: "window size 1", k: 1, arr: [5, 10, 15], want: [5, 10, 15] },
  ])("$name", ({ k, arr, want }) => {
    expect(findAverages(k, arr)).toEqual(want);
  });
});
```

Vitest finds every `*.test.ts`, so nothing needs registering. `toEqual` compares arrays and objects by value and prints the difference when they don't match; use `toBeCloseTo` to compare floats. Helpers shared by a pattern go in that folder's `shared.ts`.

### Linked lists and trees

`common/list.ts` and `common/tree.ts` hold the node types for every list and tree pattern. A missing node is `null`, and the strict type checking makes the code check for it before following `.next`. In the fast and slow pointer problems the loops also test `slow !== null`: it is always true, since the slow pointer trails the fast one, but it tells the type checker so without a `!` assertion (which the lint rules don't allow).

Tests build their inputs from literals: `buildList([1, 2, 3])` for a list and `tree([1, 2, null, 3])` for a tree in level order, with `null` for a missing child. `listValues(head)` turns a list back into an array to compare. A test that needs a cycle uses `buildNodes`, which returns every node so the last one can be pointed back.

### Heap

JavaScript has no heap (priority queue), so `common/heap.ts` has one. It is ordered by a function given to it: `new Heap<number>((a, b) => a < b)` is a min heap, and `(a, b) => a > b` a max heap. For anything bigger than a number, the function says which item goes on top, so a heap of objects or tuples needs no negating tricks. `pop()` and `peek()` return `undefined` when the heap is empty, and `remove(item)` takes an item out of the middle, which the sliding window median needs.

Where the answer depends on how ties are broken (rearranging letters, k-largest pairs), the heaps use the same rule as the Rust, C++ and Python folders, so the tests check exact answers.

### Queues

An array is the queue in the breadth-first searches. The tree problems visit one level at a time, building the next level as a new array, and the graph problems loop over the queue with `for (const vertex of queue)`, which also visits the items pushed onto the array while the loop runs. Either way nothing is taken off the front with `shift()`, which is slow on long arrays and returns `undefined` when the array is empty.

### Trie

Go adds the trie's methods in several files of the pattern. Each TypeScript problem defines the trie class it needs instead (`Trie` with `insert`, `search` and `startsWith` in `prefixtrie.ts`, with `addWord` and `searchNode` in `searchadd.ts`, and so on), built from the shared `TrieNode` and `insert` in `trie/shared.ts`. A node keeps its children in a `Map` keyed by letter.

### How the Go code maps to TypeScript

| Go | TypeScript |
|---|---|
| `[]int`, `[][]int` | `number[]`, `number[][]` |
| `map[K]V` | `Map<K, V>`, with `(m.get(k) ?? 0) + 1` to count |
| `container/heap` | `Heap` from `common/heap.ts` |
| a slice used as a stack | an array with `push`, `pop` and `at(-1)` for the top |
| `strings.Builder` | a string built with `+=`, or an array joined with `join("")` |
| `sort.Ints`, `sort.Slice` | `arr.sort((a, b) => a - b)` (without a compare function, `sort` orders numbers as text) |
| a struct | an `interface` and object literals, or a `class` when it has methods |
| `-1` for "not found" | kept where the problem asks for it, otherwise `null` (`number \| null`) |
| `[]int` holding a fixed pair, e.g. an edge | a tuple, `[number, number]` |
| an enum made of constants | an object `as const` (`enum` isn't allowed, see above) |
| an out-parameter such as `*int` | an inner function that updates a variable of the outer one |

## Lint and Formatting

| Tool | What it checks |
|---|---|
| `tsc` (strict) | Types: every value must agree with its type, and nothing can be `undefined` or `null` without the code checking for it |
| ESLint with `typescript-eslint` (strict, type-aware) | Likely bugs and needless code, such as a condition that is always true or an `any` leaking out of a library |
| Prettier | Formatting (80 columns, 2 spaces, double quotes) |
| `make lint` | Also fails on any line over 80 characters, since Prettier leaves long comments alone |

`make fmt` formats every file; `make fmt-check` reports files that are not formatted without changing them.

## Practice Mode

To practice a pattern from scratch, use the `practice` script (run from this directory) to strip all function bodies and replace them with a stub:

```sh
./scripts/practice.sh <folder>
```

**Example:**

```sh
./scripts/practice.sh slidingwindow
```

This replaces every function body (function declarations, arrow functions, and the methods and constructors of classes) with a `// TODO:` comment and a `throw`, which type-checks for any return type:

```ts
export function findAverages(k: number, arr: number[]): number[] {
  // TODO:
  throw new Error("not implemented");
}
```

All tests still run and each test case fails with `Error: not implemented` until its function is written. Fix one function at a time and re-run tests to see your progress.

When you're done (or want to check your work), restore the originals with git:

```sh
git checkout -- slidingwindow/
```

> `shared.ts` and `*.test.ts` files are never modified.

While practicing, `make lint` fails on the imports, helpers and fields the stubs no longer use; `make test` does not.

## Debugging

To step through one problem with Node's built-in debugger:

```sh
make debug T=slidingwindow/avg CASE="window size 1"
```

This starts that problem's tests paused and attaches `node inspect` to them, stopping at the top of the test file. Without `CASE` every test case in the file runs. The test timeout is turned off, so a test doesn't fail while you're looking around.

The debugger shows the source with the types removed, on the same lines as the `.ts` file. Set a breakpoint in the solution and continue to it:

```
debug> sb('avg.ts', 12)
debug> c
```

The commands you'll use most:

| Command | What it does |
|---|---|
| `sb('avg.ts', 12)` | Break at a file and line (a warning that the script isn't loaded yet is fine; the breakpoint is set when it loads) |
| `sb('avg.ts', 12, 'windowEnd === 2')` | Break there only when a condition is true |
| `breakpoints` / `cb('avg.ts', 12)` | List breakpoints / remove one |
| `c` | Continue to the next breakpoint |
| `n` / `s` / `o` | Step over a line / step into a function / step out of it |
| `exec windowSum`, `exec arr[2]` | Print a variable or any expression |
| `watch('windowSum')` / `unwatch('windowSum')` | Print an expression every time the program stops / stop doing so |
| `list(5)` | Show the lines around the current one |
| `bt` | Print the stack trace |
| `repl` | Evaluate expressions freely in the current scope (Ctrl+C to go back) |
| `.exit` | Quit |

A `debugger;` statement in the code also stops there, without setting anything up.

For a graphical debugger, open a JavaScript Debug Terminal in VS Code and run `make test P=<folder>` there: breakpoints set in the editor are hit, with no other setup. `make debug` also works with Chrome: open `chrome://inspect` while the tests are paused.

## Editor Support

VS Code understands TypeScript out of the box. Open this folder (`typescript/`) as the workspace root so it finds `tsconfig.json` and the installed TypeScript. The ESLint, Prettier, and Vitest extensions use the copies in `node_modules/`, so they match `make check`.

## Makefile Targets

| Target | Description |
|---|---|
| `make setup` | Install the pinned tools into `node_modules/` (run automatically by every other target) |
| `make test` | Run all tests |
| `make test-verbose` | Run tests listing every test case |
| `make debug T=<folder>/<problem>` | Run one problem's tests under `node inspect` |
| `make fmt` | Format with Prettier |
| `make fmt-check` | Fail if any file is not formatted |
| `make lint` | Type-check with `tsc`, run ESLint, and fail on lines over 80 characters |
| `make check` | Run lint + tests + fmt |
| `make clean` | Remove the Vitest cache |

Add `P=<folder>` to `test` or `test-verbose` to limit it to one pattern, and `CASE="<text>"` to `test`, `test-verbose`, or `debug` to run only the test cases whose name contains that text. To start over with fresh tools, delete `node_modules/`.
