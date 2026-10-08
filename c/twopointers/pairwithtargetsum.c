#include <stdlib.h>

// Given an array of numbers sorted in ascending order and a target sum,
// find a pair in the array whose sum is equal to the given target.
//
// Write a function to return the indices of the two numbers (i.e. the pair)
// such that they add up to the given target. If no such pair exists return [-1,
// -1].
//
// Example 1:
//
// Input: [1, 2, 3, 4, 6], target=6
// Output: [1, 3]
// Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
// Example 2:
//
// Input: [2, 5, 9, 11], target=11
// Output: [0, 2]
// Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11

// The two indices are returned in a new array of length 2 that the caller
// must free.
int *search
(
    const int *arr,
    int arr_len,
    int target_sum
)
{
    int *result = malloc(2 * sizeof(int));
    int left = 0;
    int right = arr_len - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target_sum)
        {
            result[0] = left;
            result[1] = right;
            return result;
        }
        else if (sum < target_sum)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    result[0] = -1;
    result[1] = -1;
    return result;
}
