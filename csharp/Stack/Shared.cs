namespace DsaPatterns.Stack;

// Shared helpers for the stack problems.
internal static class Shared
{
    internal static string Format(IEnumerable<int> nums)
    {
        return $"[{string.Join(", ", nums)}]";
    }
}
