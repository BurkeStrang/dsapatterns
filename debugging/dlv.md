# Debugging Go Tests with Delve (dlv)

Practical notes for debugging algorithm problems using **Go + tests +
Delve**.

This guide focuses on **real workflows useful when solving algorithm/DSA
problems**.

------------------------------------------------------------------------

# Running Tests with Delve

## Debug the current package

``` bash
dlv test
```

This compiles the package and launches the debugger.

------------------------------------------------------------------------

## Debug a specific test

``` bash
dlv test -- -test.run Test_findTopKFrequentNumbers
```

The `--` passes flags to `go test`.

Example:

``` bash
dlv test -- -test.run Test_findClosestPoints
```

------------------------------------------------------------------------

## Debug a specific subtest

Example test:

``` go
t.Run("Example 1", func(t *testing.T) {})
```

Run it:

``` bash
dlv test -- -test.run "Test_findClosestPoints/Example 1"
```

------------------------------------------------------------------------

# Breakpoints

## Break on a function

    b findTopKFrequentNumbers

------------------------------------------------------------------------

## Break by file and line

    b topkelements.go:42

------------------------------------------------------------------------

## Break inside a test

    b topkelements_test.go:20

------------------------------------------------------------------------

## List breakpoints

    bp

------------------------------------------------------------------------

# Start Execution

Continue execution until the next breakpoint:

    c

------------------------------------------------------------------------

# Inspect Variables

## Print a variable

    p nums

Example output:

    []int len:7 cap:7 [1,3,5,12,11,12,11]

------------------------------------------------------------------------

## Print slice element

    p nums[2]

------------------------------------------------------------------------

## Print struct

    p point

Example:

    *Point {X:1 Y:2}

------------------------------------------------------------------------

## Print struct field

    p point.X

------------------------------------------------------------------------

# Stepping Through Code

## Step into a function

    s

------------------------------------------------------------------------

## Step over a line

    n

------------------------------------------------------------------------

## Step out of function

    so

------------------------------------------------------------------------

# Viewing Source Code

Show code around current line:

    l

------------------------------------------------------------------------

Show a specific range:

    l 30 50

------------------------------------------------------------------------

# Stack Inspection

## Print stack trace

    bt

------------------------------------------------------------------------

## Move up the stack

    up

------------------------------------------------------------------------

## Move down the stack

    down

------------------------------------------------------------------------

# Watch Variables

You can automatically display variables every step.

    display i
    display mid
    display left
    display right

This is extremely useful when debugging algorithms like:

-   binary search
-   two pointers
-   sliding window

------------------------------------------------------------------------

# Debugging Data Structures

## Heap

If your heap is a pointer:

``` go
maxHeap := &MaxHeap{}
heap.Init(maxHeap)
```

Print contents:

    p *maxHeap

------------------------------------------------------------------------

## Slice

    p nums

------------------------------------------------------------------------

## Map

    p freq

------------------------------------------------------------------------

## Length

    p len(nums)

------------------------------------------------------------------------

# Example Debug Session

Algorithm:

``` go
func findKthSmallestNumber(nums []int, k int) int
```

Start debugging:

``` bash
dlv test -- -test.run Test_findKthSmallestNumber
```

Inside dlv:

    b findKthSmallestNumber
    c
    p nums
    p k
    display i
    display nums[i]
    n
    n
    n

------------------------------------------------------------------------

# Debugging Recursion

Example recursive function:

    findUniqueTreesRecursive

Set breakpoint:

    b findUniqueTreesRecursive

Inspect variables:

    p start
    p end
    bt

The stack trace helps visualize recursive calls.

------------------------------------------------------------------------

# Useful Trick: Run Only One Test

Run normally first:

``` bash
go test -run Test_findClosestPoints -v
```

Then debug it:

``` bash
dlv test -- -test.run Test_findClosestPoints
```

------------------------------------------------------------------------

# Disable Compiler Optimizations

Optimizations can make stepping confusing.

Run Delve with:

``` bash
dlv test -- -gcflags="all=-N -l"
```

This disables optimizations and inlining.

------------------------------------------------------------------------

# Suggested Workflow for Algorithm Practice

1.  Write the test
2.  Run tests

``` bash
go test ./... -v
```

3.  Debug failing test

``` bash
dlv test -- -test.run Test_problem
```

4.  Break on algorithm

```{=html}
<!-- -->
```
    b functionName

5.  Step through execution

```{=html}
<!-- -->
```
    display i
    display mid
    display left
    display right
    n
    n
    n

This effectively gives a **live trace of your algorithm**.

------------------------------------------------------------------------

# Exit Delve

    exit

or

    q

------------------------------------------------------------------------

# Summary

Key commands you'll use most when debugging algorithms:

    dlv test ./topkelements -- -test.run Test_minimumCostToConnectRopes
    b minimumCostToConnectRopes
    c
    n
    s
    p minHeap
    display variable
    bt

This workflow makes debugging Go algorithm problems much easier.
