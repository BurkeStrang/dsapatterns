#include "cyclicalsort/shared.h"

// Given an unsorted array containing numbers, find the smallest missing
// positive number in it.
//
// Note: Positive numbers start from '1'.
//
// Example 1:
//
// Input: [-3, 1, 5, 4, 2]
// Output: 3
// Explanation: The smallest missing positive number is '3'
// Example 2:
//
// Input: [3, -2, 0, 1, 2]
// Output: 4
// Example 3:
//
// Input: [3, 2, 5, 1]
// Output: 4
// Example 4:
//
// Input: [33, 37, 5]
// Output: 1
// Constraints:
//
// 1 <= nums.length <=
// -231 <= nums[i] <= 231 - 1

int find_mis
(
    int *nums,
    int nums_len
)
{
    int i = 0;
    // Rearrange the elements to place each positive integer at its correct
    // index. Negative numbers and numbers greater than the array size are
    // ignored.
    while (i < nums_len)
    {
        if (nums[i] > 0 && nums[i] <= nums_len && nums[i] != nums[nums[i] - 1])
        {
            swap(nums, i, nums[i] - 1);
        }
        else
        {
            i++;
        }
    }

    // Find the first index where the element does not match its expected
    // positive value.
    for (i = 0; i < nums_len; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }

    // If all elements from 1 to nums_len are present, return nums_len + 1.
    return nums_len + 1;
}
