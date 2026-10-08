namespace DsaPatterns.CyclicalSort;

// Shared helpers for the cyclic sort problems.
internal static class Shared
{
    // Swaps two elements in the array at positions i and j.
    internal static void Swap(int[] arr, int i, int j)
    {
        (arr[i], arr[j]) = (arr[j], arr[i]);
    }

    internal static string Format(IEnumerable<int> nums)
    {
        return $"[{string.Join(", ", nums)}]";
    }
}
