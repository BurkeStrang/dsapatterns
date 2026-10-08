namespace DsaPatterns.SlidingWindow;

// Shared types and helpers for the sliding window problems.
internal static class Shared
{
    internal static bool EqualDoubles(
        double[] a,
        double[] b,
        double epsilon = 1e-9
    )
    {
        if (a.Length != b.Length)
        {
            return false;
        }

        for (int i = 0; i < a.Length; i++)
        {
            if (Math.Abs(a[i] - b[i]) > epsilon)
            {
                return false;
            }
        }

        return true;
    }

    // Reports whether a and b hold the same rows, ignoring the order of the
    // rows (the numbers within a row must be in the same order).
    internal static bool EqualUnordered2D(
        IReadOnlyList<IReadOnlyList<int>> a,
        IReadOnlyList<IReadOnlyList<int>> b
    )
    {
        if (a.Count != b.Count)
        {
            return false;
        }

        bool[] used = new bool[b.Count];
        foreach (IReadOnlyList<int> x in a)
        {
            bool found = false;
            for (int j = 0; j < b.Count; j++)
            {
                if (!used[j] && x.SequenceEqual(b[j]))
                {
                    used[j] = true;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                return false;
            }
        }

        return true;
    }

    internal static string Format(IEnumerable<int> nums)
    {
        return $"[{string.Join(", ", nums)}]";
    }

    internal static string Format2D(IEnumerable<IEnumerable<int>> rows)
    {
        return $"[{string.Join(", ", rows.Select(Format))}]";
    }
}
