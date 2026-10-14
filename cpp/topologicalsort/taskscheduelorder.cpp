#include <array>
#include <queue>
#include <vector>

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

std::vector<int>
find_order(int tasks, const std::vector<std::array<int, 2>> &prerequisites)
{
    std::vector<int> sorted_order;

    // Initialize the graph
    std::vector<int> in_degree(tasks);
    std::vector<std::vector<int>> graph(tasks);

    // Build the graph
    for (auto [parent, child] : prerequisites)
    {
        graph[parent].push_back(child);
        in_degree[child]++;
    }

    // Find all sources i.e., all vertices with 0 in-degrees
    std::queue<int> sources;
    for (int vertex = 0; vertex < tasks; vertex++)
    {
        if (in_degree[vertex] == 0)
        {
            sources.push(vertex);
        }
    }

    // For each source, add it to the sorted_order and subtract one from all
    // of its children's in-degrees. If a child's in-degree becomes zero, add
    // it to sources queue.
    while (!sources.empty())
    {
        int vertex = sources.front();
        sources.pop();
        sorted_order.push_back(vertex);
        for (int child : graph[vertex])
        {
            if (--in_degree[child] == 0)
            {
                sources.push(child);
            }
        }
    }

    // If sorted_order doesn't contain all tasks, there is a cyclic dependency
    // between tasks, therefore, we will not be able to schedule all tasks
    if (std::ssize(sorted_order) != tasks)
    {
        return {};
    }

    return sorted_order;
}
