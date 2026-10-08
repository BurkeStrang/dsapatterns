namespace DsaPatterns.Subsets;

// Shared helpers for the subsets problems.
internal static class Shared
{
    // Sorts the numbers within each row, then sorts the rows, so two results
    // can be compared regardless of the order they were found in.
    internal static int[][] SortRows(IEnumerable<IEnumerable<int>> rows)
    {
        int[][] sorted = rows.Select(row => row.Order().ToArray()).ToArray();
        Array.Sort(sorted, CompareRows);
        return sorted;
    }

    internal static string Format<T>(IEnumerable<T> items)
    {
        return $"[{string.Join(", ", items)}]";
    }

    internal static string Format2D(IEnumerable<IEnumerable<int>> rows)
    {
        return $"[{string.Join(", ", rows.Select(Format))}]";
    }

    private static int CompareRows(int[] a, int[] b)
    {
        for (int k = 0; k < Math.Min(a.Length, b.Length); k++)
        {
            if (a[k] != b[k])
            {
                return a[k].CompareTo(b[k]);
            }
        }

        return a.Length.CompareTo(b.Length);
    }
}
