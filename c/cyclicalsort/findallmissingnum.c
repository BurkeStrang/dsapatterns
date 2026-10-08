#include "common/list.h"
#include "cyclicalsort/shared.h"

// We are given an unsorted array containing numbers taken from the range 1 to
// ‘n’.
// The array can have duplicates, which means some numbers will be missing.
// Find all those missing numbers.
//
// Example 1:
// Input: [2, 3, 1, 8, 2, 3, 5, 1]
// Output: 4, 6, 7
// Explanation: The array should have all numbers from 1 to 8,
// due to duplicates 4, 6, and 7 are missing.
//
// Example 2:
// Input: [2, 4, 1, 2]
// Output: 3
//
// Example 3:
// Input: [2, 3, 2, 1]
// Output: 4
// Constraints:
//
// n == nums.length
// 1 <= n <=
// 1 <= nums[i] <= n

// The missing numbers are returned in a list that the caller must free.
IntList find_numbers
(
    int *nums,
    int nums_len
)
{
    int i = 0; // Initialize a pointer for iterating through the array.
    while (i < nums_len)
    {
        if (nums[i] != nums[nums[i] - 1])
        {
            // Swap the current element with the element at its correct
            // position.
            swap(nums, i, nums[i] - 1);
        }
        else
        {
            i++;
        }
    }

    IntList missing_numbers = {0};
    for (i = 0; i < nums_len; i++)
    {
        if (nums[i] != i + 1)
        {
            // If the element at index 'i' is not in the correct position, add
            // it to the missing numbers list.
            intlist_push(&missing_numbers, i + 1);
        }
    }
    return missing_numbers;
}
