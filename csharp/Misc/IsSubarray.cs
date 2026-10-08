namespace DsaPatterns.Misc;

internal static class IsSubarray
{
    internal static bool Contains(int[] nums, int[] sub)
    {
        int n = sub.Length;
        for (int i = 0; i + n <= nums.Length; i++)
        {
            if (nums.AsSpan(i, n).SequenceEqual(sub))
            {
                return true;
            }
        }

        return false;
    }
}
