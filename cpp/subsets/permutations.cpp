#include <queue>
#include <vector>

// Given a set of distinct numbers, find all of its permutations.
//
// Example 1:
// Input: [1,3,5]
// Output: [1,3,5], [1,5,3], [3,1,5], [3,5,1], [5,1,3], [5,3,1]

std::vector<std::vector<int>> find_permutations(const std::vector<int> &nums)
{
    std::vector<std::vector<int>> result;
    std::queue<std::vector<int>> permutations;
    permutations.push({});
    for (int current_number : nums)
    {
        // we will take all existing permutations and add the current number
        // to create new permutations
        int n = std::ssize(permutations);
        for (int i = 0; i < n; i++)
        {
            std::vector<int> old_permutation = permutations.front();
            permutations.pop();
            // create a new permutation by adding the current number at every
            // position
            for (int j = 0; j <= std::ssize(old_permutation); j++)
            {
                std::vector<int> new_permutation = old_permutation;
                new_permutation.insert(new_permutation.begin() + j,
                                       current_number);
                if (new_permutation.size() == nums.size())
                {
                    result.push_back(new_permutation);
                }
                else
                {
                    permutations.push(new_permutation);
                }
            }
        }
    }
    return result;
}
