# DSA Patterns — C#

C# implementations of the DSA patterns. Each pattern has its own folder (and namespace) with clean, self-contained implementations and table-driven unit tests.

## Patterns

| Pattern | Problems |
|---|---|
| [Sliding Window](./SlidingWindow/) | 1 |

## Getting Started

**Requirements:** .NET SDK 10.0+

All commands run from this directory (`csharp/`):

```sh
# Run all tests
make test

# Run tests with verbose output
make test-verbose

# Run lint + tests + fmt (full quality gate)
make check
```

## Project Structure

Everything is a single xUnit project (`DsaPatterns.csproj`), so solutions and their tests live side by side and tests can call `internal` code directly. Each pattern lives in its own folder and namespace (`DsaPatterns.<Pattern>`). Every problem has:
- An implementation file with a comment describing the problem, examples, and constraints
- A paired `*Tests.cs` file with table-driven tests (`[Theory]` + `TheoryData`)

```
csharp/
├── DsaPatterns.csproj
├── SlidingWindow/
│   ├── Shared.cs          # shared types and helpers
│   ├── Avg.cs             # problem implementation
│   ├── AvgTests.cs        # table-driven tests
│   └── ...
└── ...
```

## Practice Mode

To practice a pattern from scratch, use the `practice` script (run from this directory) to strip all method bodies and replace them with a `// TODO` stub that still compiles:

```sh
./scripts/practice.sh <folder>
```

**Example:**

```sh
./scripts/practice.sh SlidingWindow
```

This replaces every solution method body with a `// TODO:` comment and a `throw` that compiles. For example:

```csharp
internal static double[] FindAverages(int k, int[] arr)
{
    // TODO:
    throw new System.NotImplementedException();
}
```

All tests still run and each unimplemented method shows a clear failure (`System.NotImplementedException`) per test case. Fix one method at a time and re-run tests to see your progress.

When you're done (or want to check your work), restore the originals with git:

```sh
git checkout -- SlidingWindow/
```

> `Shared.cs` files, `*Tests.cs` files, and equality/ordering methods (`Equals`, `GetHashCode`, `ToString`, `CompareTo`, `Compare`) are never modified.

## Makefile Targets

| Target | Description |
|---|---|
| `make build` | Compile the project |
| `make test` | Run all tests |
| `make test-verbose` | Run tests with verbose output |
| `make fmt` | Format with CSharpier (wraps code at 80 characters) |
| `make lint` | Build with analyzers, warnings as errors; fail on lines over 80 characters |
| `make check` | Run lint + tests + fmt |
| `make clean` | Remove build artifacts |
