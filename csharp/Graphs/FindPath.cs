namespace DsaPatterns.Graphs;

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

internal static class FindPath
{
    internal static bool ValidPath(int n, int[][] edges, int start, int end)
    {
        List<int>[] graph = new List<int>[n];

        // Initialize the graph
        for (int i = 0; i < n; i++)
        {
            graph[i] = [];
        }

        // Populate the graph from edges
        foreach (int[] edge in edges)
        {
            graph[edge[0]].Add(edge[1]);
            graph[edge[1]].Add(edge[0]); // Because it's an undirected graph
        }

        bool[] visited = new bool[n];
        return Dfs(graph, start, end, visited);
    }

    private static bool Dfs(
        List<int>[] graph,
        int node,
        int end,
        bool[] visited
    )
    {
        if (node == end)
        {
            return true; // Found the path
        }

        visited[node] = true;

        // Traverse neighbors
        foreach (int neighbor in graph[node])
        {
            if (!visited[neighbor] && Dfs(graph, neighbor, end, visited))
            {
                return true;
            }
        }

        return false; // Path not found
    }
}
