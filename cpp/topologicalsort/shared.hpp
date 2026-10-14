#pragma once

#include <array>
#include <vector>

// is_topological_order reports whether order lists every vertex once, with
// each edge's parent before its child. A graph usually has more than one
// valid order, so the tests check the order this way instead of comparing it
// with a fixed answer.
inline bool is_topological_order(const std::vector<int> &order, int vertices,
                                 const std::vector<std::array<int, 2>> &edges)
{
    if (std::ssize(order) != vertices)
    {
        return false;
    }

    // position[v] is where vertex 'v' sits in the order, or -1
    std::vector<int> position(vertices, -1);
    for (int i = 0; i < std::ssize(order); i++)
    {
        int vertex = order[i];
        if (vertex < 0 || vertex >= vertices || position[vertex] != -1)
        {
            return false;
        }
        position[vertex] = i;
    }

    for (auto [parent, child] : edges)
    {
        if (position[parent] > position[child])
        {
            return false;
        }
    }
    return true;
}
