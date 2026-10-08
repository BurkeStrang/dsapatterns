#include "common/heap.h"

// Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.
// Example 1:
// Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
// Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]
//
// Example 2:
// Input: L1=[5, 8, 9], L2=[1, 7]
// Output: [1, 5, 7, 8, 9]

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

// min-heap order for a heap of node pointers: the smallest value comes first
bool list_node_less
(
    const void *a,
    const void *b
)
{
    const ListNode *x = *(ListNode *const *)a;
    const ListNode *y = *(ListNode *const *)b;
    return x->val < y->val;
}

// merge merges the given lists into one sorted list.
ListNode *merge
(
    ListNode **lists,
    int lists_len
)
{
    Heap min_heap = heap_new(sizeof(ListNode *), list_node_less);

    // put the root of each list in the min heap
    for (int i = 0; i < lists_len; i++)
    {
        if (lists[i] != NULL)
        {
            heap_push(&min_heap, &lists[i]);
        }
    }

    // take the smallest (top) element form the min-heap and add it to the
    // result; if the top element has a next element add it to the heap
    ListNode *result_head = NULL;
    ListNode *result_tail = NULL;
    while (min_heap.len > 0)
    {
        ListNode *node;
        heap_pop(&min_heap, &node);
        if (result_head == NULL)
        {
            result_head = node;
            result_tail = node;
        }
        else
        {
            result_tail->next = node;
            result_tail = result_tail->next;
        }

        if (node->next != NULL)
        {
            heap_push(&min_heap, &node->next);
        }
    }

    heap_free(&min_heap);
    return result_head;
}
