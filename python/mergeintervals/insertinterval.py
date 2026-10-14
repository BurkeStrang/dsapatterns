"""
Given a list of non-overlapping intervals sorted by their start time,
insert a given interval at the correct position and merge all necessary
intervals
to produce a list that has only mutually exclusive intervals.

Example 1:
Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,6]
Output: [[1,3], [4,7], [8,12]]
Explanation: After insertion, since [4,6] overlaps with [5,7], we merged them
into one [4,7].

Example 2:
Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,10]
Output: [[1,3], [4,12]]
Explanation: After insertion, since [4,10] overlaps with [5,7] & [8,12], we
merged them into [4,12].

Example 3:
Input: Intervals=[[2,3],[5,7]], New Interval=[1,4]
Output: [[1,4], [5,7]]
Explanation: After insertion, since [1,4] overlaps with [2,3], we merged them
into one [1,4].

Constraints:
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
"""

from mergeintervals.shared import Interval


def insert(intervals: list[Interval], new_interval: Interval) -> list[Interval]:
    merged_intervals: list[Interval] = []
    start, end = new_interval.start, new_interval.end
    i = 0
    n = len(intervals)
    # skip (and add to output) all intervals that come before the
    # 'new_interval'
    while i < n and intervals[i].end < start:
        merged_intervals.append(intervals[i])
        i += 1

    # merge all intervals that overlap with 'new_interval'
    while i < n and intervals[i].start <= end:
        start = min(start, intervals[i].start)
        end = max(end, intervals[i].end)
        i += 1

    # insert the new_interval
    merged_intervals.append(Interval(start, end))

    # add all the remaining intervals to the output
    while i < n:
        merged_intervals.append(intervals[i])
        i += 1
    return merged_intervals
