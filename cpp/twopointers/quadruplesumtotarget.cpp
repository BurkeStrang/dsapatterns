#include <algorithm>
#include <vector>

// Given an array of unsorted numbers and a target number,
// find all unique quadruplets in it, whose sum is equal to the target number.
//
// Example 1:
//
// Input: [4, 1, 2, -1, 1, -3], target=1
// Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
// Explanation: Both the quadruplets add up to the target.
// Example 2:
//
// Input: [2, 0, -1, 1, -2, 2], target=2
// Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
// Explanation: Both the quadruplets add up to the target.
// Constraints:
//
// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

void search_pairs(const std::vector<int> &arr, int target_sum, int first,
                  int second, std::vector<std::vector<int>> &quadruplets)
{
    int left = second + 1;
    int right = std::ssize(arr) - 1;
    while (left < right)
    {
        int sum = arr[first] + arr[second] + arr[left] + arr[right];
        if (sum == target_sum)
        {
            // found the quadruplet
            quadruplets.push_back(
                {arr[first], arr[second], arr[left], arr[right]});
            left++;
            right--;
            // skip same elements to avoid duplicate quadruplets
            while (left < right && arr[left] == arr[left - 1])
            {
                left++;
            }
            while (left < right && arr[right] == arr[right + 1])
            {
                right--;
            }
        }
        else if (sum < target_sum)
        {
            left++; // we need a pair with a bigger sum
        }
        else
        {
            right--; // we need a pair with a smaller sum
        }
    }
}

std::vector<std::vector<int>> search_quadruplets(std::vector<int> &arr,
                                                 int target)
{
    std::ranges::sort(arr);
    std::vector<std::vector<int>> quadruplets;
    for (int i = 0; i < std::ssize(arr) - 3; i++)
    {
        // skip same element to avoid duplicate quadruplets
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < std::ssize(arr) - 2; j++)
        {
            // skip same element to avoid duplicate quadruplets
            if (j > i + 1 && arr[j] == arr[j - 1])
            {
                continue;
            }
            search_pairs(arr, target, i, j, quadruplets);
        }
    }
    return quadruplets;
}
