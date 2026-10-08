package mergeintervals

// Given two lists of intervals, find the intersection of these two lists.
// Each list consists of disjoint intervals sorted on their start time.
//
// Example 1:
// Input: arr1=[[1, 3], [5, 6], [7, 9]], arr2=[[2, 3], [5, 7]]
// Output: [2, 3], [5, 6], [7, 7]
// Explanation: The output list contains the common intervals between the two lists.
//
// Example 2:
// Input: arr1=[[1, 3], [5, 7], [9, 12]], arr2=[[5, 10]]
// Output: [5, 7], [9, 10]
// Explanation: The output list contains the common intervals between the two lists.
//
// Constraints:
// 0 <= arr1.length, arr2.length <= 1000
// arr1.length + arr2.length >= 1
// 0 <= starti < endi <= 109
// endi < starti+1
// 0 <= startj < endj <= 109
// endj < startj+1

func intersectingIntervals(arr1, arr2 []Interval) []Interval {
	var result []Interval
	i, j := 0, 0
	for i < len(arr1) && j < len(arr2) {
		// check if the interval arr1[i] intersects with arr2[j]
		// check if one of the interval's start time lies within the other interval
		if (arr1[i].Start >= arr2[j].Start && arr1[i].Start <= arr2[j].End) ||
			(arr2[j].Start >= arr1[i].Start && arr2[j].Start <= arr1[i].End) {
			// store the intersection part
			result = append(result, Interval{Start: max(arr1[i].Start, arr2[j].Start), End: min(arr1[i].End, arr2[j].End)})
		}

		// move next from the interval which is finishing first
		if arr1[i].End < arr2[j].End {
			i++
		} else {
			j++
		}
	}
	return result
}
