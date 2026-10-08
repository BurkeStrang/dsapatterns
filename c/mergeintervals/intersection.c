#include "mergeintervals/shared.h"

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

// The intersections are returned in a new array that the caller must free,
// and its length is stored in result_len.
Interval *intersecting_intervals
(
    const Interval *arr1,
    int arr1_len,
    const Interval *arr2,
    int arr2_len,
    int *result_len
)
{
    // two lists can't have more intersections than intervals between them
    Interval *result =
        malloc(((size_t)arr1_len + (size_t)arr2_len + 1) * sizeof(Interval));
    int len = 0;
    int i = 0;
    int j = 0;
    while (i < arr1_len && j < arr2_len)
    {
        // check if the interval arr1[i] intersects with arr2[j]
        // check if one of the interval's start time lies within the other
        // interval
        if ((arr1[i].start >= arr2[j].start && arr1[i].start <= arr2[j].end) ||
            (arr2[j].start >= arr1[i].start && arr2[j].start <= arr1[i].end))
        {
            // store the intersection part
            int start =
                arr1[i].start > arr2[j].start ? arr1[i].start : arr2[j].start;
            int end = arr1[i].end < arr2[j].end ? arr1[i].end : arr2[j].end;
            result[len++] = (Interval){start, end};
        }

        // move next from the interval which is finishing first
        if (arr1[i].end < arr2[j].end)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    *result_len = len;
    return result;
}
