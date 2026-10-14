#include <array>
#include <vector>

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

void print_all_topological_sorts(const std::vector<std::vector<int>> &graph,
                                 std::vector<int> &in_degree,
                                 const std::vector<int> &sources,
                                 std::vector<int> &sorted_order,
                                 std::vector<std::vector<int>> &orders)
{
    for (std::size_t i = 0; i < sources.size(); i++)
    {
        int vertex = sources[i];
        sorted_order.push_back(vertex);

        // Copy the sources for the next call, leaving out the current vertex
        std::vector<int> sources_for_next_call = sources;
        sources_for_next_call.erase(sources_for_next_call.begin() + i);

        const std::vector<int> &children = graph[vertex];
        for (int child : children)
        {
            if (--in_degree[child] == 0)
            {
                sources_for_next_call.push_back(child);
            }
        }

        print_all_topological_sorts(graph, in_degree, sources_for_next_call,
                                    sorted_order, orders);

        // Backtrack: take the vertex out again and restore the in-degrees
        sorted_order.pop_back();
        for (int child : children)
        {
            in_degree[child]++;
        }
    }

    // If sorted_order doesn't contain all tasks, either we've a cyclic
    // dependency between tasks, or we have not processed all the tasks in
    // this recursive call
    if (sorted_order.size() == in_degree.size())
    {
        orders.push_back(sorted_order);
    }
}

std::vector<std::vector<int>>
print_orders(int tasks, const std::vector<std::array<int, 2>> &prerequisites)
{
    std::vector<std::vector<int>> orders;
    if (tasks <= 0)
    {
        return orders;
    }

    // a. Initialize the graph
    std::vector<int> in_degree(tasks);
    std::vector<std::vector<int>> graph(tasks);

    // b. Build the graph
    for (auto [parent, child] : prerequisites)
    {
        graph[parent].push_back(child);
        in_degree[child]++;
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    std::vector<int> sources;
    for (int vertex = 0; vertex < tasks; vertex++)
    {
        if (in_degree[vertex] == 0)
        {
            sources.push_back(vertex);
        }
    }

    std::vector<int> sorted_order;
    print_all_topological_sorts(graph, in_degree, sources, sorted_order,
                                orders);
    return orders;
}
