#include "common/list.h"
#include "common/queue.h"

// There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’.
// Each task can have some prerequisite tasks which need to be completed before
// it can be scheduled.
// Given the number of tasks and a list of prerequisite pairs,
// write a method to find the ordering of tasks we should pick to finish all
// tasks.
//
// Example 1:
// Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
// Output: [0 1 4 3 2 5]
// Explanation: A possible scheduling of tasks is: [0 1 4 3 2 5]
//
// Example 2:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
// Output: [0, 1, 2]
// Explanation: To execute task '1', task '0' needs to finish first.
// Similarly, task '1' needs to finish before '2' can be scheduled.
// A possible scheduling of tasks is: [0, 1, 2]
//
// Example 3:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2], [2, 0]
// Output: []
// Explanation: The tasks have a cyclic dependency, therefore they cannot be
// scheduled.

// The order is returned in a list that the caller must free; it is empty
// when the tasks can't all be scheduled.
IntList find_order
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

    // If sorted_order doesn't contain all tasks, there is a cyclic dependency
    // between tasks, therefore, we will not be able to schedule all tasks
    if (sorted_order.len != vertices)
    {
        intlist_free(&sorted_order);
    }
    return sorted_order;
}
