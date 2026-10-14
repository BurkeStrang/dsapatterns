#include <vector>

// You are given a directed graph with n nodes, labeled from 0 to n-1.
// This graph is described by a 2D integer array graph,
// indicating there is a directed edge from node i to each of the nodes in
// graph[i].
// A node is called a terminal node if it has no outgoing edges.
// A node is considered safe if every path starting from that node leads to a
// terminal node (or another safe node).
// Return an array of all safe nodes in ascending order.
//
// Example 1:
// Input: graph = [[1,2],[2,3],[2],[],[5],[6],[]]
// Expected Output: [3,4,5,6]
// Explanation:
// Node 3 is a terminal node.
// Node 4 leads to node 5, which is a safe node.
// Node 5 leads to node 6, which is a terminal node.
// Node 6 is a terminal node.
//
// Example 2:
// Input: graph = [[1,2],[2,3],[5],[0],[],[],[4]]
// Expected Output: [2,4,5,6]
// Explanation:
// Node 2 leads to node 5, which is a terminal node.
// Node 4 is a terminal node.
// Node 5 is a terminal node.
// Node 6 leads to node 4, which is a terminal node.
//
// Example 3:
// Input: graph = [[1,2,3],[2,3],[3],[],[0,1,2]]
// Expected Output: [0,1,2,3,4]
// Explanation:
// Node 3 is a terminal node.
// Node 2 leads to node 3, which is a terminal node.
// Node 1 leads to node 2, which is a safe node, and node 3, which is a terminal
// node.
// Similarly, all node leads to either a terminal or a safe node.
// Constraints:
//
// n == graph.length
// 1 <= n <= 104
// 0 <= graph[i].length <= n
// 0 <= graph[i][j] <= n - 1
// graph[i] is sorted in a strictly increasing order.
// The graph may contain self-loops.
// The number of edges in the graph will be in the range [1, 4 * 104].

enum class State
{
    unvisited,
    visiting,
    safe,
};

bool dfs(const std::vector<std::vector<int>> &graph,
         std::vector<State> &visited, int node)
{
    if (visited[node] == State::safe)
    {
        return true; // If node is marked as safe
    }
    if (visited[node] == State::visiting)
    {
        return false; // If node is part of a cycle
    }

    visited[node] = State::visiting; // Mark the node as visiting
    for (int next : graph[node])
    {
        if (!dfs(graph, visited, next))
        {
            return false; // If any adjacent node is not safe
        }
    }

    visited[node] = State::safe; // Mark the node as safe
    return true;
}

std::vector<int> eventual_safe_nodes(const std::vector<std::vector<int>> &graph)
{
    int n = std::ssize(graph);
    std::vector<State> visited(n, State::unvisited);
    std::vector<int> result;

    // the nodes are tried in order, so the result comes out sorted
    for (int i = 0; i < n; i++)
    {
        if (dfs(graph, visited, i))
        {
            result.push_back(i);
        }
    }

    return result;
}
