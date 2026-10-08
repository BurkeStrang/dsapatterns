namespace DsaPatterns.Graphs;

// Shared helpers for the graph problems.
internal static class Shared
{
    internal static string Format(IEnumerable<int> nums)
    {
        return $"[{string.Join(", ", nums)}]";
    }
}
