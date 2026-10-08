namespace DsaPatterns.IslandTraversal;

// Shared helpers for the island traversal problems.
internal static class Shared
{
    // Defensive deep copy so tests are not mutated during traversal
    internal static int[][] CopyMatrix(int[][] m)
    {
        return m.Select(row => row.ToArray()).ToArray();
    }

    internal static bool[][] NewVisited(int rows, int cols)
    {
        bool[][] visited = new bool[rows][];
        for (int i = 0; i < rows; i++)
        {
            visited[i] = new bool[cols];
        }

        return visited;
    }

    internal static string Format2D(int[][] rows)
    {
        IEnumerable<string> parts = rows.Select(row =>
            $"[{string.Join(", ", row)}]"
        );
        return $"[{string.Join(", ", parts)}]";
    }
}
