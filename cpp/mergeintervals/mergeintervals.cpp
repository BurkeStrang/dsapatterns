#include "mergeintervals/shared.hpp"

#include <algorithm>
#include <vector>

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

std::vector<Interval> merge(std::vector<Interval> &intervals)
{
    if (intervals.size() < 2)
    {
        return intervals;
    }

    // sort the intervals by start time
    std::ranges::sort(intervals, {}, &Interval::start);

    std::vector<Interval> merged_intervals;
    int start = intervals[0].start;
    int end = intervals[0].end;
    for (const Interval &interval : intervals)
    {
        if (interval.start <= end)
        {
            // overlapping intervals, adjust the 'end'
            end = std::max(end, interval.end);
        }
        else
        {
            // non-overlapping interval, add the previous interval and reset
            merged_intervals.push_back({start, end});
            start = interval.start;
            end = interval.end;
        }
    }

    // add the last interval
    merged_intervals.push_back({start, end});
    return merged_intervals;
}
