namespace DsaPatterns.MergeIntervals;

internal record struct Interval(int Start, int End);

// Shared helpers for the merge intervals problems.
internal static class Shared
{
    // Builds intervals from [start, end] pairs, to keep test data compact.
    internal static Interval[] ToIntervals(int[][] pairs)
    {
        return pairs.Select(pair => new Interval(pair[0], pair[1])).ToArray();
    }

    internal static string Format(IEnumerable<Interval> intervals)
    {
        IEnumerable<string> parts = intervals.Select(interval =>
            $"[{interval.Start}, {interval.End}]"
        );
        return $"[{string.Join(", ", parts)}]";
    }
}
