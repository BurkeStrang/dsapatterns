#include <algorithm>
#include <vector>

// Given two arrays, find if the second one is a subarray of the first: its
// numbers appear in the first array next to each other and in the same order.

bool is_subarray(const std::vector<int> &nums, const std::vector<int> &sub)
{
    for (std::size_t i = 0; i + sub.size() <= nums.size(); i++)
    {
        if (std::equal(sub.begin(), sub.end(), nums.begin() + i))
        {
            return true;
        }
    }
    return false;
}
