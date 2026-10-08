namespace DsaPatterns.TopologicalSort;

// Shared helpers for the topological sort problems.
internal static class Shared
{
    // Reports whether order lists every vertex exactly once, with the parent
    // of each [parent, child] edge placed before the child. A graph can have
    // several valid orders, so tests check the order instead of comparing it
    // with one fixed answer.
    internal static bool IsTopologicalOrder(
        IReadOnlyList<int> order,
        int vertices,
        int[][] edges
    )
    {
        if (!order.Order().SequenceEqual(Enumerable.Range(0, vertices)))
        {
            return false;
        }

        int[] position = new int[vertices];
        for (int i = 0; i < order.Count; i++)
        {
            position[order[i]] = i;
        }

        return edges.All(edge => position[edge[0]] < position[edge[1]]);
    }

    internal static string Format(IEnumerable<int> nums)
    {
        return $"[{string.Join(", ", nums)}]";
    }
}
