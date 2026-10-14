#include <algorithm>
#include <vector>

// Given a set of numbers that might contain duplicates, find all of its
// distinct subsets.
//
// Example 1:
// Input: [1, 3, 3]
// Output: [], [1], [3], [1,3], [3,3], [1,3,3]
//
// Example 2:
// Input: [1, 5, 3, 3]
// Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3], [3,3], [1,3,3],
// [3,3,5], [1,5,3,3]

std::vector<std::vector<int>> find_dup_subsets(std::vector<int> &nums)
{
    // sort the numbers to handle duplicates
    std::ranges::sort(nums);
    std::vector<std::vector<int>> subsets = {{}};
    // the subsets added in the previous step start here
    int previous_step_start = 0;
    for (int i = 0; i < std::ssize(nums); i++)
    {
        int start_index = 0;
        // if current and the previous elements are same, create new subsets
        // only from the subsets added in the previous step
        if (i > 0 && nums[i] == nums[i - 1])
        {
            start_index = previous_step_start;
        }
        previous_step_start = std::ssize(subsets);
        for (int j = start_index; j < previous_step_start; j++)
        {
            // create a new subset from the existing subset and add the
            // current element to it
            std::vector<int> set = subsets[j];
            set.push_back(nums[i]);
            subsets.push_back(set);
        }
    }
    return subsets;
}
