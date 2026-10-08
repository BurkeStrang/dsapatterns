// Shared types and helpers for the fast and slow pointers problems.
#ifndef DSAPATTERNS_FASTANDSLOWPOINTERS_SHARED_H
#define DSAPATTERNS_FASTANDSLOWPOINTERS_SHARED_H

#include "common/list.h"

#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

// list_from builds a linked list holding the given values and returns its
// head, or NULL for an empty list. All the nodes live in one block of memory
// that starts at the first node, so keep the returned pointer and pass it to
// free once the test is done, however the list has been rearranged.
//
// If cycle_start is not -1, the last node is linked back to the node at that
// index, creating a cycle.
static inline ListNode *list_from_with_cycle
(
    const int *vals,
    int len,
    int cycle_start
)
{
    if (len == 0)
    {
        return NULL;
    }
    ListNode *nodes = malloc((size_t)len * sizeof(ListNode));
    for (int i = 0; i < len; i++)
    {
        nodes[i].val = vals[i];
        nodes[i].next = i + 1 < len ? &nodes[i + 1] : NULL;
    }
    if (cycle_start != -1)
    {
        nodes[len - 1].next = &nodes[cycle_start];
    }
    return nodes;
}

static inline ListNode *list_from
(
    const int *vals,
    int len
)
{
    return list_from_with_cycle(vals, len, -1);
}

// list_values collects the values of a list, in order, so two lists can be
// compared. The caller frees the result. It stops after 10000 nodes in case
// the list has a cycle.
static inline IntList list_values
(
    const ListNode *head
)
{
    IntList vals = {0};
    for (int i = 0; head != NULL && i < 10000; i++)
    {
        intlist_push(&vals, head->val);
        head = head->next;
    }
    return vals;
}

#endif
