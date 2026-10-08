#include "common/list.h"

// Given an array of integers arr, return the sum of the minimum values from all
// possible contiguous subarrays within arr.
// Since the result can be very large, return the final sum modulo (109 + 7).
//
// Example 1:
// Input: arr = [3, 1, 2, 4, 5]
// Expected Output: 30
// Explanation:
// The subarrays are: [3], [1], [2], [4], [5], [3,1], [1,2], [2,4], [4,5],
// [3,1,2], [1,2,4], [2,4,5], [3,1,2,4], [1, 2, 4, 5], [3, 1, 2, 4, 5].
// The minimum values of these subarrays are: 3, 1, 2, 4, 5, 1, 1, 2, 4, 1, 1,
// 2, 1, 1, 1.
// Summing these minimums: 3 + 1 + 2 + 4 + 5 + 1 + 1 + 2 + 4 + 1 + 1 + 2 + 1 + 1
// + 1 = 30.
//
// Example 2:
// Input: arr = [2, 6, 5, 4]
// Expected Output: 36
// Explanation:
// The subarrays are: [2], [6], [5], [4], [2,6], [6,5], [5,4], [2,6,5], [6,5,4],
// [2,6,5,4].
// The minimum values of these subarrays are: 2, 6, 5, 4, 2, 5, 4, 2, 4, 2.
// Summing these minimums: 2 + 6 + 5 + 4 + 2 + 5 + 4 + 2 + 4 + 2 = 36.
//
// Example 3:
// Input: arr = [7, 3, 8]
// Expected Output: 35
// Explanation:
// The subarrays are: [7], [3], [8], [7,3], [3,8], [7,3,8].
// The minimum values of these subarrays are: 7, 3, 8, 3, 3, 3.
// Summing these minimums: 7 + 3 + 8 + 3 + 3 + 3 = 27.
//
// Constraints:
// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104

int sum_subarray_mins
(
    const int *arr,
    int n
)
{
    const long long mod = 1000000007;
    long long result = 0; // Final sum of subarray minimums
    IntList stack = {0};

    // Iterate through the array plus one extra iteration for a sentinel.
    for (int current_index = 0; current_index <= n; current_index++)
    {
        // If we reached the end, use 0 as a sentinel value; otherwise, use
        // the current element. It helps to process all remaining elements in
        // the stack.
        int current_element = 0;
        if (current_index < n)
        {
            current_element = arr[current_index];
        }

        // Process elements in the stack while the current element is smaller
        // than the element at the top. Here, we maintain monotonic increasing
        // stack.
        while (stack.len > 0 &&
               arr[stack.items[stack.len - 1]] > current_element)
        {
            // Pop the index whose corresponding element is greater than
            // current_element.
            int min_index = intlist_pop(&stack);

            // Determine the previous index from the stack; if the stack is
            // empty, use -1.
            int previous_index = -1;
            if (stack.len > 0)
            {
                previous_index = stack.items[stack.len - 1];
            }

            // Calculate the number of subarrays where arr[min_index] is the
            // minimum: (min_index - previous_index) gives the count of
            // subarrays ending at min_index, and (current_index - min_index)
            // gives the count of subarrays starting at min_index that can
            // extend until current_index.
            long long count_subarrays =
                (long long)(min_index - previous_index) *
                (current_index - min_index);

            // Add the contribution of arr[min_index] for these subarrays to
            // the result.
            result = (result + arr[min_index] * count_subarrays % mod) % mod;
        }

        // Push the current index onto the stack for further processing.
        intlist_push(&stack, current_index);
    }

    intlist_free(&stack);
    return (int)(result % mod);
}
