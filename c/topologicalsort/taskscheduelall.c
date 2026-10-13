#include "common/list.h"

// There are N tasks, labeled from 0 to 'N-1'.
// Each task can have some prerequisite tasks which need to be completed before
// it can be scheduled.
//
// Given the number of tasks and a list of prerequisite pairs,
// write a method to print all possible ordering of tasks meeting all
// prerequisites.
//
// Example 1:
// Input: Tasks=4, Prerequisites=[3, 2], [3, 0], [2, 0], [2, 1]
// Output:
// 1) [3, 2, 0, 1]
// 2) [3, 2, 1, 0]
// Explanation: There are two possible orderings of the tasks meeting all
// prerequisites.
//
// Example 2:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
// Output: [0, 1, 2]
// Explanation: There is only possible ordering of the tasks.
//
// Example 3:
// Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
// Output:
// 1) [0, 1, 4, 3, 2, 5]
// 2) [0, 1, 3, 4, 2, 5]
// 3) [0, 1, 3, 2, 4, 5]
// 4) [0, 1, 3, 2, 5, 4]
// 5) [1, 0, 3, 4, 2, 5]
// 6) [1, 0, 3, 2, 4, 5]
// 7) [1, 0, 3, 2, 5, 4]
// 8) [1, 0, 4, 3, 2, 5]
// 9) [1, 3, 0, 2, 4, 5]
// 10) [1, 3, 0, 2, 5, 4]
// 11) [1, 3, 0, 4, 2, 5]
// 12) [1, 3, 2, 0, 5, 4]
// 13) [1, 3, 2, 0, 4, 5]

// print_all_topological_sorts tries every source as the next task, and adds
// each complete ordering to orders.
void print_all_topological_sorts
(
    const IntList *graph,
    int *in_degree,
    int tasks,
    const IntList *sources,
    IntList *sorted_order,
    IntMatrix *orders
)
{
    for (int i = 0; i < sources->len; i++)
    {
        int vertex = sources->items[i];
        intlist_push(sorted_order, vertex);

        // Copy the sources for the next call, leaving out the current vertex
        IntList sources_for_next_call = {0};
        for (int s = 0; s < sources->len; s++)
        {
            if (s != i)
            {
                intlist_push(&sources_for_next_call, sources->items[s]);
            }
        }

        const IntList *children = &graph[vertex];
        for (int c = 0; c < children->len; c++)
        {
            int child = children->items[c];
            in_degree[child]--;
            if (in_degree[child] == 0)
            {
                intlist_push(&sources_for_next_call, child);
            }
        }

        print_all_topological_sorts(graph, in_degree, tasks,
                                    &sources_for_next_call, sorted_order,
                                    orders);
        intlist_free(&sources_for_next_call);

        // Backtrack: take the vertex out again and restore the in-degrees
        intlist_pop(sorted_order);
        for (int c = 0; c < children->len; c++)
        {
            in_degree[children->items[c]]++;
        }
    }

    // If sorted_order doesn't contain all tasks, either we've a cyclic
    // dependency between tasks, or we have not processed all the tasks in
    // this recursive call
    if (sorted_order->len == tasks)
    {
        intmatrix_push(orders, intlist_copy(sorted_order));
    }
}

// Every ordering is returned as a row of a matrix that the caller must free;
// it is empty when the tasks can't all be scheduled.
IntMatrix print_orders
(
    int tasks,
    const IntMatrix *prerequisites
)
{
    IntMatrix orders = {0};
    if (tasks <= 0)
    {
        return orders;
    }

    // a. Initialize the graph
    // count of incoming edges for every vertex
    int *in_degree = calloc((size_t)tasks, sizeof(int));
    // adjacency list graph
    IntList *graph = calloc((size_t)tasks, sizeof(IntList));

    // b. Build the graph
    for (int i = 0; i < prerequisites->len; i++)
    {
        int parent = prerequisites->rows[i].items[0];
        int child = prerequisites->rows[i].items[1];
        intlist_push(&graph[parent], child);
        in_degree[child]++;
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    IntList sources = {0};
    for (int vertex = 0; vertex < tasks; vertex++)
    {
        if (in_degree[vertex] == 0)
        {
            intlist_push(&sources, vertex);
        }
    }

    IntList sorted_order = {0};
    print_all_topological_sorts(graph, in_degree, tasks, &sources,
                                &sorted_order, &orders);

    intlist_free(&sorted_order);
    intlist_free(&sources);
    for (int i = 0; i < tasks; i++)
    {
        intlist_free(&graph[i]);
    }
    free(graph);
    free(in_degree);
    return orders;
}
