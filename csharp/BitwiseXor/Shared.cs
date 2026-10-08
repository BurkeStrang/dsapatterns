namespace DsaPatterns.BitwiseXor;

// Shared helpers for the bitwise XOR problems.
internal static class Shared
{
    // Reports whether a and b hold the same numbers, ignoring order.
    internal static bool EqualUnordered(int[] a, int[] b)
    {
        return a.Order().SequenceEqual(b.Order());
    }

    internal static bool Equal2D(int[][] a, int[][] b)
    {
        if (a.Length != b.Length)
        {
            return false;
        }

        for (int i = 0; i < a.Length; i++)
        {
            if (!a[i].SequenceEqual(b[i]))
            {
                return false;
            }
        }

        return true;
    }

    internal static string Format2D(int[][] rows)
    {
        return "["
            + string.Join(", ", rows.Select(r => $"[{string.Join(", ", r)}]"))
            + "]";
    }
}
