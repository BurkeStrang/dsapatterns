#include "common/list.h"

// Given an array with positive numbers and a positive target number,
// find all of its contiguous subarrays whose product is less than the target
// number.
//
// Note: This problem is very similar to the previous one.
// Here, we are trying to find all the subarrays, whereas in the previous
// problem, we focused on finding only the count of such subarrays.
//
// Example 1:
// Input: [2, 5, 3, 10], target=30
// Output: [2], [5], [2, 5], [3], [5, 3], [10]
// Explanation: There are six contiguous subarrays whose product is less than
// the target.
//
// Example 2:
// Input: [8, 2, 6, 5], target=50
// Output: [8], [2], [8, 2], [6], [2, 6], [5], [6, 5]
// Explanation: There are seven contiguous subarrays whose product is less than
// the target.
//
// Constraints:
// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 1000
// 0 <= k <= 106

// The subarrays are returned in a matrix that the caller must free.
IntMatrix find_subarrays
(
    const int *arr,
    int arr_len,
    int target
)
{
    // Resultant list to store all valid subarrays.
    IntMatrix result = {0};
    // Variable to store the product of elements in the current subarray.
    int product = 1;
    // Left boundary of the current subarray.
    int left = 0;
    // Iterate over the array using 'right' as the right boundary of the
    // current subarray.
    for (int right = 0; right < arr_len; right++)
    {
        // Update the product with the current element.
        product *= arr[right];
        // If the product is greater than or equal to the target, slide the
        // left boundary to the right until product is less than target.
        while (product >= target && left < arr_len)
        {
            product /= arr[left];
            left++;
        }
        // Temporary list to store the current subarray.
        IntList temp_list = {0};
        // Iterate from 'right' to 'left' and add all these subarrays to the
        // result.
        for (int i = right; i >= left; i--)
        {
            // Add the current element at the beginning of the list.
            intlist_insert(&temp_list, 0, arr[i]);
            // Add the current subarray to the result.
            intmatrix_push(&result, intlist_copy(&temp_list));
        }
        intlist_free(&temp_list);
    }
    // Return the result.
    return result;
}
