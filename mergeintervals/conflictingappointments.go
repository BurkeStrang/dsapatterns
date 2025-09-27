package mergeintervals

import "sort"

// Given an array of intervals representing ‘N’ appointments, find out if a person can attend all the appointments.
//
// Example 1:
// Intervals: [[1,4], [2,5], [7,9]]
// Output: false
// Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.
//
// Example 2:
// Intervals: [[6,7], [2,4], [13, 14], [8,12], [45, 47]]
// Output: true
// Explanation: None of the appointments overlap, therefore a person can attend all of them.
//
// Example 3:
// Intervals: [[4,5], [2,3], [3,6]]
// Output: false
// Explanation: Since [4,5] and [3,6] overlap, a person cannot attend both of these appointments.
//
// Constraints:
// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti < endi <= 106

func canAttendAllAppointments(intervals []Interval) bool {
	// sort the intervals by start time
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i].Start < intervals[j].Start
	})

	// find any overlapping appointment
	for i := 1; i < len(intervals); i++ {
		if intervals[i].Start < intervals[i-1].End {
			// please note the comparison above, it is "<" and not "<="
			// while merging we needed "<=" comparison, as we will be merging the two
			// intervals having condition "intervals[i].Start == intervals[i - 1].End" but
			// such intervals don't represent conflicting appointments as one starts right
			// after the other
			return false
		}
	}
	return true
}
