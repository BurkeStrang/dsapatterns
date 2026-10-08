#include <stdbool.h>
#include <stdlib.h>

// Given an array of numbers sorted in ascending order, find the range of a
// given number ‘key’.
// The range of the ‘key’ will be the first and last position of the ‘key’ in
// the array.
// Write a function to return the range of the ‘key’. If the ‘key’ is not
// present return [-1, -1].
//
// Example 1:
// Input: [4, 6, 6, 6, 9], key = 6
// Output: [1, 3]
//
// Example 2:
// Input: [1, 3, 8, 10, 15], key = 10
// Output: [3, 3]
//
// Example 3:
// Input: [1, 3, 8, 10, 15], key = 12
// Output: [-1, -1]

int search
(
    const int *arr,
    int arr_len,
    int key,
    bool find_max_index
)
{
    int key_index = -1;
    int start = 0;
    int end = arr_len - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (key < arr[mid])
        {
            end = mid - 1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        { // key == arr[mid]
            key_index = mid;
            if (find_max_index)
            {
                // search ahead to find the last index of 'key'
                start = mid + 1;
            }
            else
            {
                // search behind to find the first index of 'key'
                end = mid - 1;
            }
        }
    }
    return key_index;
}

// The range is returned in a new array of length 2 that the caller must
// free.
int *find_range
(
    const int *arr,
    int arr_len,
    int key
)
{
    int *result = malloc(2 * sizeof(int));
    result[0] = search(arr, arr_len, key, false);
    result[1] = -1;
    // no need to search, if 'key' is not present in the input array
    if (result[0] != -1)
    {
        result[1] = search(arr, arr_len, key, true);
    }
    return result;
}
