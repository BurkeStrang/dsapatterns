#include <array>
#include <queue>
#include <vector>

// Topological Sort of a directed graph (a graph with unidirectional edges) is
// a linear ordering of its vertices such that for every directed edge (U, V)
// from vertex U to vertex V, U comes before V in the ordering.
//
// Given a directed graph, find the topological ordering of its vertices.
// Returns an empty list if the graph has a cycle.

std::vector<int> sort(int vertices,
                      const std::vector<std::array<int, 2>> &edges)
{
    std::vector<int> sorted_order;

    // a. Initialize the graph
    std::vector<int> in_degree(vertices);          // count of incoming edges
    std::vector<std::vector<int>> graph(vertices); // adjacency list graph

    // b. Build the graph
    for (auto [parent, child] : edges)
    {
        graph[parent].push_back(child); // put the child into its parent's list
        in_degree[child]++;             // increment child's in_degree
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    std::queue<int> sources;
    for (int vertex = 0; vertex < vertices; vertex++)
    {
        if (in_degree[vertex] == 0)
        {
            sources.push(vertex);
        }
    }

    // d. For each source, add it to the sorted_order and subtract one from
    // all of its children's in-degrees if a child's in-degree becomes zero,
    // add it to sources queue
    while (!sources.empty())
    {
        int vertex = sources.front();
        sources.pop();
        sorted_order.push_back(vertex);
        // get the node's children to decrement their in-degrees
        for (int child : graph[vertex])
        {
            if (--in_degree[child] == 0)
            {
                sources.push(child);
            }
        }
    }

    // if topological sort is not possible as the graph has a cycle
    if (std::ssize(sorted_order) != vertices)
    {
        return {};
    }

    return sorted_order;
}
