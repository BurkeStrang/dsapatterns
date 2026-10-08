#include "common/heap.h"

// Design a class to efficiently find the Kth largest element in a stream of
// numbers.
// The class should have the following two things:
// The constructor of the class should accept an integer array containing
// initial numbers from the stream and an integer ‘K’.
// The class should expose a function add(int num) which will store the given
// number and return the Kth largest number.
//
// Example 1:
// Input: [3, 1, 5, 12, 2, 11], K = 4
// 1. Calling add(6) should return '5'.
// 2. Calling add(13) should return '6'.
// 2. Calling add(4) should still return '6'.

typedef struct
{
    Heap min_heap; // min heap to store the k largest elements seen so far
    int k;         // The value of 'k'
} KthLargest;

int kth_largest_add
(
    KthLargest *stream,
    int num
)
{
    int_heap_push(&stream->min_heap, num);
    if (stream->min_heap.len > stream->k)
    {
        int_heap_pop(&stream->min_heap);
    }
    return int_heap_top(&stream->min_heap);
}

KthLargest kth_largest_new
(
    const int *nums,
    int nums_len,
    int k
)
{
    KthLargest result = {int_min_heap_new(), k};
    for (int i = 0; i < nums_len; i++)
    {
        kth_largest_add(&result, nums[i]);
    }
    return result;
}

void kth_largest_free
(
    KthLargest *stream
)
{
    heap_free(&stream->min_heap);
}
