#include "common/list.h"
#include "common/queue.h"

// We are given an undirected graph that has the characteristics of a k-ary
// tree.
// In such a graph,
// we can choose any node as the root to make a k-ary tree.
// The root (or the tree) with the minimum height will be called Minimum Height
// Tree (MHT).
// There can be multiple MHTs for a graph.
// In this problem, we need to find all those roots which give us MHTs.
// Write a method to find all MHTs of the given graph and return a list of their
// roots.
//
// Example 1:
// Input: vertices: 5, Edges: [[0, 1], [1, 2], [1, 3], [2, 4]]
// Output:[1, 2]
// Explanation: Choosing '1' or '2' as roots give us MHTs.
// In the below diagram,
// we can see that the height of the trees with roots '1' or '2' is three which
// is the minimum.
//
// Example 2:
// Input: vertices: 4, Edges: [[0, 1], [0, 2], [2, 3]]
// Output:[0, 2]
// Explanation: Choosing '0' or '2' as roots give us MHTs.
// In the below diagram, we can see that the height of the trees with roots '0'
// or '2' is three which is minimum.
//
// Example 3:
// Input: vertices: 4, Edges: [[0, 1], [1, 2], [1, 3]]
// Output:[1]
//
// Constraints:
// 1 <= vertices <= 2 * 104
// edges.length == n - 1
// 0 <= ai, bi < n
// ai != bi
// All the pairs (ai, bi) are distinct.
// The given input is guaranteed to be a tree and there will be no repeated
// edges.

// The roots are returned in a list that the caller must free.
IntList find_trees
(
    int nodes,
    const IntMatrix *edges
)
{
    IntList min_height_trees = {0};
    if (nodes <= 0)
    {
        return min_height_trees;
    }

    // with only one node, since its in-degree will be 0, therefore, we need
    // to handle it separately
    if (nodes == 1)
    {
        intlist_push(&min_height_trees, 0);
        return min_height_trees;
    }

    // a. Initialize the graph
    // count of incoming edges for every vertex
    int *in_degree = calloc((size_t)nodes, sizeof(int));
    // adjacency list graph
    IntList *graph = calloc((size_t)nodes, sizeof(IntList));

    // b. Build the graph
    for (int i = 0; i < edges->len; i++)
    {
        int n1 = edges->rows[i].items[0];
        int n2 = edges->rows[i].items[1];
        // since this is an undirected graph, therefore, add a link for both
        // the nodes
        intlist_push(&graph[n1], n2);
        intlist_push(&graph[n2], n1);
        // increment the in-degrees of both the nodes
        in_degree[n1]++;
        in_degree[n2]++;
    }

    // c. Find all leaves i.e., all nodes with only 1 in-degree
    Queue leaves = queue_new(sizeof(int));
    for (int vertex = 0; vertex < nodes; vertex++)
    {
        if (in_degree[vertex] == 1)
        {
            int_queue_push(&leaves, vertex);
        }
    }

    // d. Remove leaves level by level and subtract each leave's children's
    // in-degrees. Repeat this until we are left with 1 or 2 nodes, which will
    // be our answer. Any node that has already been a leaf cannot be the root
    // of a minimum height tree, because its adjacent non-leaf node will
    // always be a better candidate.
    int total_nodes = nodes;
    while (total_nodes > 2)
    {
        int leaves_size = leaves.len;
        total_nodes -= leaves_size;
        for (int i = 0; i < leaves_size; i++)
        {
            int vertex = int_queue_pop(&leaves);
            for (int c = 0; c < graph[vertex].len; c++)
            {
                int child = graph[vertex].items[c];
                in_degree[child]--;
                if (in_degree[child] == 1) // if the child has become a leaf
                {
                    int_queue_push(&leaves, child);
                }
            }
        }
    }

    while (leaves.len > 0)
    {
        intlist_push(&min_height_trees, int_queue_pop(&leaves));
    }

    queue_free(&leaves);
    for (int i = 0; i < nodes; i++)
    {
        intlist_free(&graph[i]);
    }
    free(graph);
    free(in_degree);
    return min_height_trees;
}
