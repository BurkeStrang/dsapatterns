#include "common/heap.h"

// Given an array,
// find the sum of all numbers between the K1’th and K2’th smallest elements of
// that array.
//
// Example 1:
// Input: [1, 3, 12, 5, 15, 11], and K1=3, K2=6
// Output: 23
// Explanation: The 3rd smallest number is 5 and 6th smallest number 15. The sum
// of numbers coming
// between 5 and 15 is 23 (11+12).

// Example 2:
// Input: [3, 5, 8, 7], and K1=1, K2=4
// Output: 12
// Explanation: The sum of the numbers between the 1st smallest number (3) and
// the 4th smallest
// number (8) is 12 (5+7).

int find_sum_of_elements
(
    const int *nums,
    int nums_len,
    int k1,
    int k2
)
{
    Heap min_heap = int_min_heap_new();

    // Insert all numbers into the min heap
    for (int i = 0; i < nums_len; i++)
    {
        int_heap_push(&min_heap, nums[i]);
    }

    // Remove k1 smallest numbers from the min heap
    for (int i = 0; i < k1; i++)
    {
        int_heap_pop(&min_heap);
    }

    int element_sum = 0;
    // Sum next k2-k1-1 numbers
    for (int i = 0; i < k2 - k1 - 1; i++)
    {
        element_sum += int_heap_pop(&min_heap);
    }

    heap_free(&min_heap);
    return element_sum;
}
