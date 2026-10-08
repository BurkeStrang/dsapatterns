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
}
