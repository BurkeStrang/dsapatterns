use super::shared::Interval;

// Given two lists of intervals, find the intersection of these two lists.
// Each list consists of disjoint intervals sorted on their start time.
//
// Example 1:
// Input: arr1=[[1, 3], [5, 6], [7, 9]], arr2=[[2, 3], [5, 7]]
// Output: [2, 3], [5, 6], [7, 7]
// Explanation: The output list contains the common intervals between the two
// lists.
//
// Example 2:
// Input: arr1=[[1, 3], [5, 7], [9, 12]], arr2=[[5, 10]]
// Output: [5, 7], [9, 10]
// Explanation: The output list contains the common intervals between the two
// lists.
//
// Constraints:
// 0 <= arr1.length, arr2.length <= 1000
// arr1.length + arr2.length >= 1
// 0 <= starti < endi <= 109
// endi < starti+1
// 0 <= startj < endj <= 109
// endj < startj+1

pub fn intersecting_intervals(
    arr1: &[Interval],
    arr2: &[Interval],
) -> Vec<Interval> {
    let mut result = Vec::new();
    let mut i = 0;
    let mut j = 0;
    while i < arr1.len() && j < arr2.len() {
        // check if the interval arr1[i] intersects with arr2[j]
        // check if one of the interval's start time lies within the other
        // interval
        if (arr1[i].start >= arr2[j].start && arr1[i].start <= arr2[j].end)
            || (arr2[j].start >= arr1[i].start && arr2[j].start <= arr1[i].end)
        {
            // store the intersection part
            result.push(Interval {
                start: arr1[i].start.max(arr2[j].start),
                end: arr1[i].end.min(arr2[j].end),
            });
        }

        // move next from the interval which is finishing first
        if arr1[i].end < arr2[j].end {
            i += 1;
        } else {
            j += 1;
        }
    }
    result
}
