#include <optional>
#include <utility>
#include <vector>

// Given a sorted array and a target sum, find the indices of a pair of
// numbers that add up to the target. Returns None if there is no such pair.

std::optional<std::pair<int, int>> search(const std::vector<int> &arr,
                                          int target_sum)
{
    int left = 0;
    int right = std::ssize(arr) - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target_sum)
        {
            return std::pair{left, right};
        }
        if (sum < target_sum)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return std::nullopt;
}
