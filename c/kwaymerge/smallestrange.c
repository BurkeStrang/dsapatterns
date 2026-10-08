#include "common/heap.h"
#include "common/list.h"

#include <limits.h>

// Given ‘M’ sorted arrays, find the smallest range that includes at least one
// number from each of the ‘M’ lists.
// Example 1:
// Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
// Output: [4, 7]
// Explanation: The range [4, 7] includes 5 from L1, 4 from L2 and 7 from L3.
//
// Example 2:
// Input: L1=[1, 9], L2=[4, 12], L3=[7, 10, 16]
// Output: [9, 12]
// Explanation: The range [9, 12] includes 9 from L1, 12 from L2 and 10 from L3

// NodeElement is a position in one of the lists, with the number found there.
typedef struct
{
    int value;
    int element_index;
    int array_index;
} NodeElement;

// min-heap order: the smallest number comes first
bool node_element_less
(
    const void *a,
    const void *b
)
{
    return ((const NodeElement *)a)->value < ((const NodeElement *)b)->value;
}

// The range is returned in a new array of length 2 that the caller must
// free.
int *find_smallest_range
(
    const IntMatrix *lists
)
{
    Heap min_heap = heap_new(sizeof(NodeElement), node_element_less);

    int range_start = 0;
    int range_end = INT_MAX;
    int current_max_number = INT_MIN;

    for (int i = 0; i < lists->len; i++)
    {
        if (lists->rows[i].len > 0)
        {
            int first = lists->rows[i].items[0];
            heap_push(&min_heap, &(NodeElement){first, 0, i});
            if (first > current_max_number)
            {
                current_max_number = first;
            }
        }
    }

    while (min_heap.len == lists->len)
    {
        NodeElement node;
        heap_pop(&min_heap, &node);
        if (range_end - range_start > current_max_number - node.value)
        {
            range_start = node.value;
            range_end = current_max_number;
        }

        node.element_index++;
        const IntList *list = &lists->rows[node.array_index];
        if (list->len > node.element_index)
        {
            node.value = list->items[node.element_index];
            heap_push(&min_heap, &node);
            if (node.value > current_max_number)
            {
                current_max_number = node.value;
            }
        }
    }

    heap_free(&min_heap);
    int *result = malloc(2 * sizeof(int));
    result[0] = range_start;
    result[1] = range_end;
    return result;
}
