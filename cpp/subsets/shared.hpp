#pragma once

#include <algorithm>
#include <vector>

// sorted_subsets sorts each subset and then the list of subsets, so that two
// lists holding the same subsets in a different order compare equal.
inline std::vector<std::vector<int>>
sorted_subsets(std::vector<std::vector<int>> subsets)
{
    for (std::vector<int> &subset : subsets)
    {
        std::ranges::sort(subset);
    }
    std::ranges::sort(subsets);
    return subsets;
}
