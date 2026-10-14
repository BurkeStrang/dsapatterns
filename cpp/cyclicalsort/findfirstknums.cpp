#include <unordered_set>
#include <utility>
#include <vector>

// Given an unsorted array containing numbers and a number ‘k’,
// find the first ‘k’ missing positive numbers in the array.
//
// Example 1:
// Input: [3, -1, 4, 5, 5], k=3
// Output: [1, 2, 6]
// Explanation: The smallest missing positive numbers are 1, 2 and 6.
//
// Example 2:
// Input: [2, 3, 4], k=3
// Output: [1, 5, 6]
// Explanation: The smallest missing positive numbers are 1, 5 and 6.
//
// Example 3:
// Input: [-2, -3, 4], k=2
// Output: [1, 2]
// Explanation: The smallest missing positive numbers are 1 and 2.
// Constraints:
//
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 1000
// 1 <= k <= 1000

std::vector<int> find_first_k(std::vector<int> &nums, int k)
{
    int n = std::ssize(nums);
    int i = 0;

    // Phase 1: Rearrange elements to their correct positions
    while (i < n)
    {
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
        {
            // Swap elements to their correct positions
            std::swap(nums[i], nums[nums[i] - 1]);
        }
        else
        {
            i++;
        }
    }

    std::vector<int> missing_numbers;
    std::unordered_set<int> extra_numbers;

    // Phase 2: Identify missing and extra numbers
    for (int j = 0; j < n && std::ssize(missing_numbers) < k; j++)
    {
        if (nums[j] != j + 1)
        {
            missing_numbers.push_back(j + 1); // Track missing numbers
            extra_numbers.insert(nums[j]);    // Track extra numbers
        }
    }

    // Phase 3: Find remaining missing numbers
    int candidate_number = n + 1;
    while (std::ssize(missing_numbers) < k)
    {
        // Ignore if the array contains the candidate number
        if (!extra_numbers.contains(candidate_number))
        {
            missing_numbers.push_back(candidate_number);
        }
        candidate_number++;
    }

    return missing_numbers;
}
