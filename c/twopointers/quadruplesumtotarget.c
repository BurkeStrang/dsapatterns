#include "common/list.h"
#include "common/sort.h"

// Given an array of unsorted numbers and a target number,
// find all unique quadruplets in it, whose sum is equal to the target number.
//
// Example 1:
//
// Input: [4, 1, 2, -1, 1, -3], target=1
// Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
// Explanation: Both the quadruplets add up to the target.
// Example 2:
//
// Input: [2, 0, -1, 1, -2, 2], target=2
// Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
// Explanation: Both the quadruplets add up to the target.
// Constraints:
//
// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

void search_pairs
(
    const int *arr,
    int arr_len,
    int target_sum,
    int first,
    int second,
    IntMatrix *quadruplets
)
{
    int left = second + 1;
    int right = arr_len - 1;
    while (left < right)
    {
        int sum = arr[first] + arr[second] + arr[left] + arr[right];
        if (sum == target_sum)
        { // found the quadruplet
            int quadruplet[] = {arr[first], arr[second], arr[left], arr[right]};
            intmatrix_push(quadruplets, intlist_from(quadruplet, 4));
            left++;
            right--;
            while (left < right && arr[left] == arr[left - 1])
            {
                left++; // skip same element to avoid duplicate quadruplets
            }
            while (left < right && arr[right] == arr[right + 1])
            {
                right--; // skip same element to avoid duplicate quadruplets
            }
        }
        else if (sum < target_sum)
        {
            left++; // we need a pair with a bigger sum
        }
        else
        {
            right--; // we need a pair with a smaller sum
        }
    }
}

// The quadruplets are returned in a matrix that the caller must free.
IntMatrix search_quadruplets
(
    int *arr,
    int arr_len,
    int target
)
{
    sort_ints(arr, arr_len);
    IntMatrix quadruplets = {0};
    for (int i = 0; i < arr_len - 3; i++)
    {
        // skip same element to avoid duplicate quadruplets
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < arr_len - 2; j++)
        {
            // skip same element to avoid duplicate quadruplets
            if (j > i + 1 && arr[j] == arr[j - 1])
            {
                continue;
            }
            search_pairs(arr, arr_len, target, i, j, &quadruplets);
        }
    }
    return quadruplets;
}
