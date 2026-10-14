#include <array>
#include <queue>
#include <vector>

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

std::vector<int> find_trees(int nodes,
                            const std::vector<std::array<int, 2>> &edges)
{
    if (nodes <= 0)
    {
        return {};
    }

    // with only one node, since its in-degree will be 0, therefore, we need
    // to handle it separately
    if (nodes == 1)
    {
        return {0};
    }

    // a. Initialize the graph
    std::vector<int> in_degree(nodes);          // count of incoming edges
    std::vector<std::vector<int>> graph(nodes); // adjacency list graph

    // b. Build the graph
    for (auto [n1, n2] : edges)
    {
        // since this is an undirected graph, therefore, add a link for both
        // the nodes
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
        // increment the in-degrees of both the nodes
        in_degree[n1]++;
        in_degree[n2]++;
    }

    // c. Find all leaves i.e., all nodes with only 1 in-degree
    std::queue<int> leaves;
    for (int vertex = 0; vertex < nodes; vertex++)
    {
        if (in_degree[vertex] == 1)
        {
            leaves.push(vertex);
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
        int leaves_size = std::ssize(leaves);
        total_nodes -= leaves_size;
        for (int i = 0; i < leaves_size; i++)
        {
            int vertex = leaves.front();
            leaves.pop();
            for (int child : graph[vertex])
            {
                // if the child has become a leaf
                if (--in_degree[child] == 1)
                {
                    leaves.push(child);
                }
            }
        }
    }

    std::vector<int> result;
    while (!leaves.empty())
    {
        result.push_back(leaves.front());
        leaves.pop();
    }
    return result;
}
