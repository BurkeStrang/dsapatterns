#include "common/list.h"
#include "common/sort.h"

// The subsets are returned in a matrix that the caller must free.
IntMatrix find_dup_subsets
(
    int *nums,
    int nums_len
)
{
    // sort the numbers to handle duplicates
    sort_ints(nums, nums_len);
    IntMatrix subsets = {0};
    intmatrix_push(&subsets, (IntList){0});
    int end_index = 0;
    for (int i = 0; i < nums_len; i++)
    {
        int start_index = 0;
        // if current and the previous elements are same, create new subsets
        // only from the subsets added in the previous step
        if (i > 0 && nums[i] == nums[i - 1])
        {
            start_index = end_index + 1;
        }
        end_index = subsets.len - 1;
        for (int j = start_index; j <= end_index; j++)
        {
            // create a new subset from the existing subset and add the
            // current element to it
            IntList set = intlist_copy(&subsets.rows[j]);
            intlist_push(&set, nums[i]);
            intmatrix_push(&subsets, set);
        }
    }
    return subsets;
}
