#include "common/list.h"

// example1: [1,3] => [[], [1], [3], [1,3]]
// example2: [1,5,3] => [[], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]]

// The subsets are returned in a matrix that the caller must free.
IntMatrix find_subsets
(
    const int *nums,
    int nums_len
)
{
    IntMatrix subsets = {0};
    // start by adding the empty subset
    intmatrix_push(&subsets, (IntList){0});
    // subsets = [[]]

    for (int c = 0; c < nums_len; c++)
    {
        int current_number = nums[c];
        // ===== Iteration 1 =====
        // current_number = 1

        // ===== Iteration 2 =====
        // current_number = 3

        // we will take all existing subsets and insert the current number in
        // them
        int n = subsets.len;
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
            // after append current_number:
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
            // after append:
            // set = [3]
            //
            // subsets becomes:
            // [[], [1], [3]]
            //
            // i = 1
            // subsets[1] = [1]
            // set = [1]
            // after append:
            // set = [1,3]
            //
            // subsets becomes:
            // [[], [1], [3], [1,3]]
            // ===============================
            IntList set = intlist_copy(&subsets.rows[i]);
            intlist_push(&set, current_number);
            intmatrix_push(&subsets, set);
        }
    }

    return subsets;
}
