#include "common/list.h"
#include "common/queue.h"

// The order is returned in a list that the caller must free; it is empty
// when the graph has a cycle.
IntList sort
(
    int vertices,
    const IntMatrix *edges
)
{
    IntList sorted_order = {0};
    if (vertices <= 0)
    {
        return sorted_order;
    }

    // a. Initialize the graph
    // count of incoming edges for every vertex
    int *in_degree = calloc((size_t)vertices, sizeof(int));
    // adjacency list graph
    IntList *graph = calloc((size_t)vertices, sizeof(IntList));

    // b. Build the graph
    for (int i = 0; i < edges->len; i++)
    {
        int parent = edges->rows[i].items[0];
        int child = edges->rows[i].items[1];
        // put the child into its parent's list
        intlist_push(&graph[parent], child);
        in_degree[child]++; // increment child's in-degree
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    Queue sources = queue_new(sizeof(int));
    for (int vertex = 0; vertex < vertices; vertex++)
    {
        if (in_degree[vertex] == 0)
        {
            int_queue_push(&sources, vertex);
        }
    }

    // d. For each source, add it to the sorted_order and subtract one from
    // all of its children's in-degrees. If a child's in-degree becomes zero,
    // add it to sources queue.
    while (sources.len > 0)
    {
        int vertex = int_queue_pop(&sources);
        intlist_push(&sorted_order, vertex);

        // get the node's children to decrement their in-degrees
        for (int c = 0; c < graph[vertex].len; c++)
        {
            int child = graph[vertex].items[c];
            in_degree[child]--;
            if (in_degree[child] == 0)
            {
                int_queue_push(&sources, child);
            }
        }
    }

    queue_free(&sources);
    for (int i = 0; i < vertices; i++)
    {
        intlist_free(&graph[i]);
    }
    free(graph);
    free(in_degree);

    // if topological sort is not possible as the graph has a cycle
    if (sorted_order.len != vertices)
    {
        intlist_free(&sorted_order);
    }
    return sorted_order;
}
