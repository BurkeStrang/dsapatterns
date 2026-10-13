#include "common/list.h"
#include "unionfind/shared.h"

// Given a 2D array graph[][],
// representing the undirected graph,
// where graph[u] is an array of nodes that are connected with node u.
// Determine whether a given undirected graph is a bipartite graph.
// The graph is a bipartite graph,
// if we can split the set of nodes into two distinct subsets such that
// no two nodes within the same subset are adjacent
// (i.e., no edge exists between any two nodes within a single subset).
//
// Example 1:
// Input: graph = [[1,3], [0,2], [1,3], [0,2]]
// Expected Output: true
// Justification: The nodes can be divided into two groups: {0, 2} and {1, 3}.
// No two nodes within each group are adjacent, thus the graph is bipartite.
//
// Example 2:
// Input: graph = [[1], [0], [3], [2]]
// Expected Output: true
// Justification: The graph is a simple chain of 4 nodes.
// It's clearly bipartite as we can have {0, 2} and {1, 3} as the two subsets.
//
// Example 3:
// Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
// Expected Output: false
// Justification: We found that edges (1, 2), (0, 3), and (2, 3) connect nodes
// within the same set,
// which violates the condition for a bipartite graph where each edge must
// connect nodes in different subsets.
// Thus, there's no way to divide this graph into two subsets that satisfy the
// bipartite condition.
//
// Constraints:
// graph.length == n
// 1 <= n <= 100
// 0 <= graph[u].length < n
// 0 <= graph[u][i] <= n - 1
// graph[u] does not contain u.
// All the values of graph[u] are unique.
// If graph[u] contains v, then graph[v] contains u.

bool is_bipartite
(
    const IntMatrix *graph
)
{
    UnionFind uf = uf_new(graph->len);
    bool bipartite = true;

    for (int u = 0; bipartite && u < graph->len; u++)
    {
        const IntList *neighbors = &graph->rows[u];
        if (neighbors->len == 0)
        {
            continue;
        }

        int first_neighbor = neighbors->items[0];

        for (int i = 0; i < neighbors->len; i++)
        {
            int v = neighbors->items[i];
            // a node in the same set as one of its neighbors breaks the rule
            if (uf_connected(&uf, u, v))
            {
                bipartite = false;
                break;
            }

            // all the neighbors of a node belong in the same set
            uf_union(&uf, first_neighbor, v);
        }
    }

    uf_free(&uf);
    return bipartite;
}
