#include "mergeintervals/shared.h"

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

// The merged intervals are returned in a new array that the caller must
// free, and its length is stored in result_len.
Interval *merge
(
    Interval *intervals,
    int intervals_len,
    int *result_len
)
{
    Interval *merged_intervals =
        malloc(((size_t)intervals_len + 1) * sizeof(Interval));
    int merged_len = 0;
    if (intervals_len < 2)
    {
        for (int i = 0; i < intervals_len; i++)
        {
            merged_intervals[merged_len++] = intervals[i];
        }
        *result_len = merged_len;
        return merged_intervals;
    }

    // sort the intervals by start time
    sort_intervals_by_start(intervals, intervals_len);

    int start = intervals[0].start;
    int end = intervals[0].end;

    for (int i = 0; i < intervals_len; i++)
    {
        Interval interval = intervals[i];
        if (interval.start <= end)
        {
            // overlapping intervals, adjust the 'end'
            if (interval.end > end)
            {
                end = interval.end;
            }
        }
        else
        {
            // non-overlapping interval, add the previous interval and reset
            merged_intervals[merged_len++] = (Interval){start, end};
            start = interval.start;
            end = interval.end;
        }
    }
    // add the last interval
    merged_intervals[merged_len++] = (Interval){start, end};

    *result_len = merged_len;
    return merged_intervals;
}
