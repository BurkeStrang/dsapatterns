namespace DsaPatterns.MergeIntervals;

// Given a list of non-overlapping intervals sorted by their start time,
// insert a given interval at the correct position and merge all necessary
// intervals
// to produce a list that has only mutually exclusive intervals.
//
// Example 1:
// Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,6]
// Output: [[1,3], [4,7], [8,12]]
// Explanation: After insertion, since [4,6] overlaps with [5,7], we merged them
// into one [4,7].
//
// Example 2:
// Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,10]
// Output: [[1,3], [4,12]]
// Explanation: After insertion, since [4,10] overlaps with [5,7] & [8,12], we
// merged them into [4,12].
//
// Example 3:
// Input: Intervals=[[2,3],[5,7]], New Interval=[1,4]
// Output: [[1,4], [5,7]]
// Explanation: After insertion, since [1,4] overlaps with [2,3], we merged them
// into one [1,4].
//
// Constraints:
// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 105
// intervals is sorted by starti in ascending order.
// newInterval.length == 2
// 0 <= start <= end <= 105

internal static class InsertInterval
{
    internal static List<Interval> Insert(
        Interval[] intervals,
        Interval newInterval
    )
    {
        if (intervals.Length == 0)
        {
            return [newInterval];
        }

        List<Interval> mergedIntervals = [];

        int i = 0;
        // skip (and add to output) all intervals that come before the
        // 'newInterval'
        while (i < intervals.Length && intervals[i].End < newInterval.Start)
        {
            mergedIntervals.Add(intervals[i]);
            i++;
        }

        // merge all intervals that overlap with 'newInterval'
        while (i < intervals.Length && intervals[i].Start <= newInterval.End)
        {
            newInterval.Start = Math.Min(intervals[i].Start, newInterval.Start);
            newInterval.End = Math.Max(intervals[i].End, newInterval.End);
            i++;
        }

        // insert the newInterval
        mergedIntervals.Add(newInterval);

        // add all the remaining intervals to the output
        while (i < intervals.Length)
        {
            mergedIntervals.Add(intervals[i]);
            i++;
        }

        return mergedIntervals;
    }
}
