#include "common/list.h"
#include "common/map.h"
#include "cyclicalsort/shared.h"

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

// The missing numbers are returned in a list that the caller must free.
IntList find_first_k
(
    int *nums,
    int nums_len,
    int k
)
{
    int i = 0;
    // Phase 1: Rearrange elements to their correct positions
    while (i < nums_len)
    {
        if (nums[i] > 0 && nums[i] <= nums_len && nums[i] != nums[nums[i] - 1])
        {
            // Swap elements to their correct positions
            swap(nums, i, nums[i] - 1);
        }
        else
        {
            i++;
        }
    }

    IntList missing_numbers = {0};
    IntMap extra_numbers = {0}; // used as a set of the extra numbers

    // Phase 2: Identify missing and extra numbers
    for (i = 0; i < nums_len && missing_numbers.len < k; i++)
    {
        if (nums[i] != i + 1)
        {
            intlist_push(&missing_numbers, i + 1);  // Track missing numbers
            intmap_set(&extra_numbers, nums[i], 1); // Track extra numbers
        }
    }

    // Phase 3: Find remaining missing numbers
    for (i = 1; missing_numbers.len < k; i++)
    {
        int candidate_number = i + nums_len;
        // Ignore if the array contains the candidate number
        if (!intmap_has(&extra_numbers, candidate_number))
        {
            // Add remaining missing numbers
            intlist_push(&missing_numbers, candidate_number);
        }
    }

    intmap_free(&extra_numbers);
    return missing_numbers;
}
