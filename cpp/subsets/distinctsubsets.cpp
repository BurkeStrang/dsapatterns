#include <vector>

// example1: [1,3] => [[], [1], [3], [1,3]]
// example2: [1,5,3] => [[], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]]

std::vector<std::vector<int>> find_subsets(const std::vector<int> &nums)
{
    // start by adding the empty subset
    std::vector<std::vector<int>> subsets = {{}};
    // subsets = [[]]

    for (int current_number : nums)
    {
        // ===== Iteration 1 =====
        // current_number = 1

        // ===== Iteration 2 =====
        // current_number = 3

        // we will take all existing subsets and insert the current number in
        // them
        int n = std::ssize(subsets);
        for (int i = 0; i < n; i++)
        {
            // -------- EXAMPLE WALKTHROUGH --------
            // INPUT: nums = [1,3]

            // Before any loops:
            // subsets = [[]]

            // ===============================
            // OUTER LOOP 1
            // current_number = 1
            // n = 1
            //
            // INNER LOOP:
            //
            // i = 0
            // subsets[i] = []
            // set (copy of subsets[i]) = []
            // after push current_number:
            // set = [1]
            //
            // subsets becomes:
            // [[], [1]]
            // ===============================

            // ===============================
            // OUTER LOOP 2
            // current_number = 3
            // n = 2  (because subsets now has 2 items)
            //
            // INNER LOOP:
            //
            // i = 0
            // subsets[0] = []
            // set = []
            // after push:
            // set = [3]
            //
            // subsets becomes:
            // [[], [1], [3]]
            //
            // i = 1
            // subsets[1] = [1]
            // set = [1]
            // after push:
            // set = [1,3]
            //
            // subsets becomes:
            // [[], [1], [3], [1,3]]
            // ===============================
            std::vector<int> set = subsets[i];
            set.push_back(current_number);
            subsets.push_back(set);
        }
    }

    return subsets;
}
