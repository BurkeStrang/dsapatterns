namespace DsaPatterns.KWayMerge;

// Shared helpers for the K-way merge problems.
internal static class Shared
{
    internal static string Format(IEnumerable<int> nums)
    {
        return $"[{string.Join(", ", nums)}]";
    }

    internal static string Format2D(IEnumerable<IEnumerable<int>> rows)
    {
        return $"[{string.Join(", ", rows.Select(Format))}]";
    }
}
