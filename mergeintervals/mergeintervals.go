package mergeintervals

import "sort"

// Given a list of intervals, merge all the overlapping intervals to produce a list that has only mutually exclusive intervals.
//
// Example 1:
// Intervals: [[1,4], [2,5], [7,9]]
// Output: [[1,5], [7,9]]
// Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged them into one [1,5].
//
// Example 2:
// Intervals: [[6,7], [2,4], [5,9]]
// Output: [[2,4], [5,9]]
// Explanation: Since the intervals [6,7] and [5,9] overlap, we merged them into one [5,9].
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

func merge(intervals []Interval) []Interval {
	if len(intervals) < 2 {
		return intervals
	}

	// sort the intervals by start time
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i].Start < intervals[j].Start
	})

	var mergedIntervals []Interval
	start := intervals[0].Start
	end := intervals[0].End

	for _, interval := range intervals {
		if interval.Start <= end { // overlapping intervals, adjust the 'end'
			end = max(interval.End, end)
		} else { // non-overlapping interval, add the previous interval and reset
			mergedIntervals = append(mergedIntervals, Interval{Start: start, End: end})
			start = interval.Start
			end = interval.End
		}
	}
	// add the last interval
	mergedIntervals = append(mergedIntervals, Interval{Start: start, End: end})

	return mergedIntervals
}
