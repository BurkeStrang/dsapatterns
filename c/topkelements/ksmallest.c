#include "common/heap.h"

// Given an unsorted array of numbers, find Kth smallest number in it.
// Please note that it is the Kth smallest number in the sorted order,
// not the Kth distinct element.
// Note: For a detailed discussion about different approaches to solve this
// problem,
// take a look at Kth Smallest Number.
//
// Example 1:
// Input: [1, 5, 12, 2, 11, 5], K = 3
// Output: 5
// Explanation: The 3rd smallest number is '5', as the first two smaller numbers
// are [1, 2].
//
// Example 2:
// Input: [1, 5, 12, 2, 11, 5], K = 4
// Output: 5
// Explanation: The 4th smallest number is '5', as the first three small numbers
// are [1, 2, 5].
//
// Example 3:
// Input: [5, 12, 11, -1, 12], K = 3
// Output: 11
// Explanation: The 3rd smallest number is '11', as the first two small numbers
// are [5, -1].

int find_kth_smallest_number
(
    const int *nums,
    int nums_len,
    int k
)
{
    Heap max_heap = int_max_heap_new();

    for (int i = 0; i < k; i++)
    {
        int_heap_push(&max_heap, nums[i]);
    }

    for (int i = k; i < nums_len; i++)
    {
        if (nums[i] < int_heap_top(&max_heap))
        {
            int_heap_pop(&max_heap);
            int_heap_push(&max_heap, nums[i]);
        }
    }

    int result = int_heap_top(&max_heap);
    heap_free(&max_heap);
    return result;
}
