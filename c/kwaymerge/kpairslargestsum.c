#include "common/heap.h"
#include "common/list.h"

// Given two sorted arrays in descending order,
// find ‘K’ pairs with the largest sum where each pair consists of numbers from
// both the arrays.
//
// Example 1:
// Input: nums1=[9, 8, 2], nums2=[6, 3, 1], K=3
// Output: [9, 3], [9, 6], [8, 6]
// Explanation: These 3 pairs have the largest sum. No other pair has a sum
// larger than any of these.
//
// Example 2:
// Input: nums1=[5, 2, 1], nums2=[2, -1], K=3
// Output: [5, 2], [5, -1], [2, 2]

typedef struct
{
    int first;
    int second;
} Pair;

// min-heap order: the pair with the smallest sum comes first
bool pair_sum_less
(
    const void *a,
    const void *b
)
{
    const Pair *x = a;
    const Pair *y = b;
    return x->first + x->second < y->first + y->second;
}

// find_k_largest_pairs finds k largest pairs. They are returned in a matrix,
// one pair per row, that the caller must free.
IntMatrix find_k_largest_pairs
(
    const int *nums1,
    int nums1_len,
    const int *nums2,
    int nums2_len,
    int k
)
{
    Heap min_heap = heap_new(sizeof(Pair), pair_sum_less);

    for (int i = 0; i < nums1_len && i < k; i++)
    {
        for (int j = 0; j < nums2_len && j < k; j++)
        {
            if (min_heap.len < k)
            {
                heap_push(&min_heap, &(Pair){nums1[i], nums2[j]});
            }
            else
            {
                // if the sum of the two numbers from the two arrays is
                // smaller than the smallest (top) element of the heap, we can
                // 'break' here.
                Pair top = *(Pair *)heap_top(&min_heap);
                if (nums1[i] + nums2[j] < top.first + top.second)
                {
                    break;
                }
                // we've a pair with a larger sum, remove top and insert this
                // pair in heap
                heap_pop(&min_heap, NULL);
                heap_push(&min_heap, &(Pair){nums1[i], nums2[j]});
            }
        }
    }

    IntMatrix result = {0};
    while (min_heap.len > 0)
    {
        Pair pair;
        heap_pop(&min_heap, &pair);
        int row[] = {pair.first, pair.second};
        intmatrix_push(&result, intlist_from(row, 2));
    }

    heap_free(&min_heap);
    return result;
}
