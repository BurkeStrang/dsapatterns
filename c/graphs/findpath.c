#include "common/list.h"

#include <stdbool.h>

// Given an undirected graph, represented as a list of edges.
// Each edge is illustrated as a pair of integers [u, v],
// signifying that there's a mutual connection between node u and node v.
// You are also given starting node start, and a destination node end,
// return true if a path exists between the starting node and the destination
// node.
// Otherwise, return false.
//
// Example 1:
// Input: n = 4, edges = [[0,1],[1,2],[2,3]], start = 0, end = 3
// Image
// Expected Output: true
// Justification: There's a path from node 0 -> 1 -> 2 -> 3.
//
// Example 2:
// Input: n = 4, edges = [[0,1],[2,3]], start = 0, end = 3
// Image
// Expected Output: false
// Justification: Nodes 0 and 3 are not connected, so no path exists between
// them.
//
// Example 3:
// Input: n = 5, edges = [[0,1],[3,4]], start = 0, end = 4
// Image
// Expected Output: false
// Justification: Nodes 0 and 4 are not connected in any manner.
//
// Constraints:
// 1 <= n <= 2 * 105
// 0 <= edges.length <= 2 * 105
// edges[i].length == 2
// 0 <= ui, vi <= n - 1
// ui != vi
// 0 <= source, destination <= n - 1
// There are no duplicate edges.
// There are no self edges.

bool dfs
(
    const IntList *graph,
    int node,
    int end,
    bool *visited
)
{
    if (node == end)
    {
        return true; // Found the path
    }

    visited[node] = true;

    // Traverse neighbors
    for (int i = 0; i < graph[node].len; i++)
    {
        int neighbor = graph[node].items[i];
        if (!visited[neighbor] && dfs(graph, neighbor, end, visited))
        {
            return true;
        }
    }

    return false; // Path not found
}

bool valid_path
(
    int n,
    const IntMatrix *edges,
    int start,
    int end
)
{
    // Initialize the graph
    IntList *graph = calloc((size_t)n, sizeof(IntList));

    // Populate the graph from edges
    for (int i = 0; i < edges->len; i++)
    {
        int from = edges->rows[i].items[0];
        int to = edges->rows[i].items[1];
        intlist_push(&graph[from], to);
        intlist_push(&graph[to], from); // Because it's an undirected graph
    }

    bool *visited = calloc((size_t)n, sizeof(bool));
    bool found = dfs(graph, start, end, visited);

    free(visited);
    for (int i = 0; i < n; i++)
    {
        intlist_free(&graph[i]);
    }
    free(graph);
    return found;
}
