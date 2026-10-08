// Shared helpers for the topological sort problems.
#ifndef DSAPATTERNS_TOPOLOGICALSORT_SHARED_H
#define DSAPATTERNS_TOPOLOGICALSORT_SHARED_H

#include "common/list.h"

#include <stdbool.h>
#include <stdlib.h>

// is_topological_order reports whether order lists every vertex exactly
// once, with the parent of each [parent, child] edge placed before the
// child. A graph can have several valid orders, so tests check the order
// instead of comparing it with one fixed answer.
static inline bool is_topological_order
(
    const IntList *order,
    int vertices,
    const IntMatrix *edges
)
{
    if (order->len != vertices)
    {
        return false;
    }
    int *position = malloc((size_t)vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
    {
        position[i] = -1;
    }
    bool valid = true;
    for (int i = 0; i < order->len; i++)
    {
        int vertex = order->items[i];
        if (vertex < 0 || vertex >= vertices || position[vertex] != -1)
        {
            valid = false;
            break;
        }
        position[vertex] = i;
    }
    for (int i = 0; valid && i < edges->len; i++)
    {
        int parent = edges->rows[i].items[0];
        int child = edges->rows[i].items[1];
        valid = position[parent] < position[child];
    }
    free(position);
    return valid;
}

#endif
