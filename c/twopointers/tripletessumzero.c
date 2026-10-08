#include "common/list.h"
#include "common/sort.h"

// Given an array of unsorted numbers, find all unique triplets in it that add
// up to zero.
//
// Examples
// Example 1
// Input: [-3, 0, 1, 2, -1, 1, -2]
// Output: [[-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]]
// Explanation: There are four unique triplets whose sum is equal to zero.
// Example 2
// Input: [-5, 2, -1, -2, 3]
// Output: [[-5, 2, 3], [-2, -1, 3]]
// Explanation: There are two unique triplets whose sum is equal to zero.
// Constraints:
//
// 3 <= arr.length <= 3000
// -105 <= arr[i] <= 105

void search_pair
(
    const int *arr,
    int arr_len,
    int target_sum,
    int left,
    IntMatrix *triplets
)
{
    int right = arr_len - 1;
    while (left < right)
    {
        int current_sum = arr[left] + arr[right];
        if (current_sum == target_sum)
        { // found the triplet
            int triplet[] = {-target_sum, arr[left], arr[right]};
            intmatrix_push(triplets, intlist_from(triplet, 3));
            left++;
            right--;
            while (left < right && arr[left] == arr[left - 1])
            {
                left++; // skip same element to avoid duplicate triplets
            }
            while (left < right && arr[right] == arr[right + 1])
            {
                right--; // skip same element to avoid duplicate triplets
            }
        }
        else if (target_sum > current_sum)
        {
            left++; // we need a pair with a bigger sum
        }
        else
        {
            right--; // we need a pair with a smaller sum
        }
    }
}

// The triplets are returned in a matrix that the caller must free.
IntMatrix search_triplets
(
    int *arr,
    int arr_len
)
{
    sort_ints(arr, arr_len);
    IntMatrix triplets = {0};
    for (int i = 0; i < arr_len - 2; i++)
    {
        // skip same element to avoid duplicate triplets
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        search_pair(arr, arr_len, -arr[i], i + 1, &triplets);
    }
    return triplets;
}
