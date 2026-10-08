#include "common/heap.h"
#include "common/list.h"

// Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.
//
// Example 1:
// Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
// Output: 4
// Explanation: The 5th smallest number among all the arrays is 4, this can be
// verified from
// the merged list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]
//
// Example 2:
// Input: L1=[5, 8, 9], L2=[1, 7], K=3
// Output: 7
// Explanation: The 3rd smallest number among all the arrays is 7.

// Node is a position in one of the lists, with the number found there.
typedef struct
{
    int value;
    int element_index;
    int array_index;
} Node;

// min-heap order: the smallest number comes first
bool node_value_less
(
    const void *a,
    const void *b
)
{
    return ((const Node *)a)->value < ((const Node *)b)->value;
}

int find_kth_smallest
(
    const IntMatrix *lists,
    int k
)
{
    Heap min_heap = heap_new(sizeof(Node), node_value_less);

    // put the 1st element of each array in the min heap
    for (int i = 0; i < lists->len; i++)
    {
        if (lists->rows[i].len > 0)
        {
            heap_push(&min_heap, &(Node){lists->rows[i].items[0], 0, i});
        }
    }

    // take the smallest (top) element form the min heap, if the running count
    // is equal to k return the number if the array of the top element has
    // more elements, add the next element to the heap
    int number_count = 0;
    int result = 0;
    while (min_heap.len > 0)
    {
        Node node;
        heap_pop(&min_heap, &node);
        result = node.value;
        number_count++;
        if (number_count == k)
        {
            break;
        }

        node.element_index++;
        const IntList *list = &lists->rows[node.array_index];
        if (list->len > node.element_index)
        {
            node.value = list->items[node.element_index];
            heap_push(&min_heap, &node);
        }
    }

    heap_free(&min_heap);
    return result;
}
