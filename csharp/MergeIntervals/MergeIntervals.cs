namespace DsaPatterns.MergeIntervals;

// Given a list of intervals, merge all the overlapping intervals to produce a
// list that has only mutually exclusive intervals.
//
// Example 1:
// Intervals: [[1,4], [2,5], [7,9]]
// Output: [[1,5], [7,9]]
// Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged
// them into one [1,5].
//
// Example 2:
// Intervals: [[6,7], [2,4], [5,9]]
// Output: [[2,4], [5,9]]
// Explanation: Since the intervals [6,7] and [5,9] overlap, we merged them into
// one [5,9].
//
// Example 3:
// Intervals: [[1,4], [2,6], [3,5]]
// Output: [[1,6]]
// Explanation: Since all the given intervals overlap, we merged them into one.
//
// Constraints:
// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104

internal static class MergeIntervals
{
    internal static List<Interval> Merge(Interval[] intervals)
    {
        if (intervals.Length < 2)
        {
            return [.. intervals];
        }

        // sort the intervals by start time
        Array.Sort(intervals, (a, b) => a.Start.CompareTo(b.Start));

        List<Interval> mergedIntervals = [];
        int start = intervals[0].Start;
        int end = intervals[0].End;

        foreach (Interval interval in intervals)
        {
            if (interval.Start <= end)
            {
                // overlapping intervals, adjust the 'end'
                end = Math.Max(interval.End, end);
            }
            else
            {
                // non-overlapping interval, add the previous interval and reset
                mergedIntervals.Add(new Interval(start, end));
                start = interval.Start;
                end = interval.End;
            }
        }

        // add the last interval
        mergedIntervals.Add(new Interval(start, end));

        return mergedIntervals;
    }
}
