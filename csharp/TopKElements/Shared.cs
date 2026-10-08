namespace DsaPatterns.TopKElements;

internal record struct Point(int X, int Y)
{
    public readonly int DistFromOrigin()
    {
        // ignoring sqrt
        return (X * X) + (Y * Y);
    }
}

// Shared helpers for the top K elements problems.
internal static class Shared
{
    // PriorityQueue is a min-heap by default; reversing the comparison of the
    // priorities turns it into a max-heap.
    internal static PriorityQueue<T, int> NewMaxHeap<T>()
    {
        return new PriorityQueue<T, int>(
            Comparer<int>.Create((a, b) => b.CompareTo(a))
        );
    }

    internal static string Format<T>(IEnumerable<T> items)
    {
        return $"[{string.Join(", ", items)}]";
    }
}
