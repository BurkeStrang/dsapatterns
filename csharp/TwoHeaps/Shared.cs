namespace DsaPatterns.TwoHeaps;

// Shared helpers for the two heaps problems.
internal static class Shared
{
    // PriorityQueue is a min-heap by default; reversing the comparison of the
    // priorities turns it into a max-heap.
    internal static PriorityQueue<int, int> NewMaxHeap()
    {
        return new PriorityQueue<int, int>(
            Comparer<int>.Create((a, b) => b.CompareTo(a))
        );
    }

    internal static string Format<T>(IEnumerable<T> items)
    {
        return $"[{string.Join(", ", items)}]";
    }
}
