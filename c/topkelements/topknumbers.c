#include "common/heap.h"

// Given an unsorted array of numbers, find the ‘K’ largest numbers in it.
//
// Example 1:
// Input: [3, 1, 5, 12, 2, 11], K = 3
// Output: [5, 12, 11]
//
// Example 2:
// Input: [5, 12, 11, -1, 12], K = 3
// Output: [12, 11, 12]

// findKLargestNumbers - keeps all comments same and method name same

// The k largest numbers are returned in a new array that the caller must
// free.
int *find_k_largest_numbers
(
    const int *nums,
    int nums_len,
    int k
)
{
    Heap min_heap = int_min_heap_new();

    // put first 'K' numbers in the min heap
    for (int i = 0; i < k; i++)
    {
        int_heap_push(&min_heap, nums[i]);
    }

    // go through the remaining numbers of the array, if the number from the
    // array is bigger than the top (smallest) number of the min-heap, remove
    // the top number from heap and add the number from array
    for (int i = k; i < nums_len; i++)
    {
        if (nums[i] > int_heap_top(&min_heap))
        {
            int_heap_pop(&min_heap);
            int_heap_push(&min_heap, nums[i]);
        }
    }

    // the heap has the top 'K' numbers, return them in an array
    int *result = malloc((size_t)k * sizeof(int));
    for (int i = 0; i < k; i++)
    {
        result[i] = int_heap_pop(&min_heap);
    }

    heap_free(&min_heap);
    return result;
}
