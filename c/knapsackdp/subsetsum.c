#include <stdbool.h>
#include <stdlib.h>

// Given a set of positive numbers,
// determine if a subset exists whose sum is equal to a given number ‘S’.
//
// Example 1:
// Input: {1, 2, 3, 7}, S=6
// Output: True
// The given set has a subset whose sum is '6': {1, 2, 3}
//
// Example 2:
// Input: {1, 2, 7, 1, 5}, S=10
// Output: True
// The given set has a subset whose sum is '10': {1, 2, 7}
//
// Example 3:
// Input: {1, 3, 4, 8}, S=6
// Output: False
// The given set does not have any subset whose sum is equal to '6'.
//
// Constraints:
// 1 <= num.length <= 200
// 1 <= num[i] <= 100

bool can_partition_sum
(
    const int *nums,
    int n,
    int sum
)
{
    // dp is a table of n rows and sum+1 columns; DP(i, s) is one of its cells
    int cols = sum + 1;
    bool *dp = calloc((size_t)n * (size_t)cols, sizeof(bool));
#define DP(i, s) dp[(i) * cols + (s)]

    // populate the sum=0 columns, as we can always form '0' sum with an empty
    // set
    for (int i = 0; i < n; i++)
    {
        DP(i, 0) = true;
    }

    // with only one number, we can form a subset only when the required sum
    // is equal to its value
    for (int s = 1; s <= sum; s++)
    {
        DP(0, s) = nums[0] == s;
    }

    // process all subsets for all sums
    for (int i = 1; i < n; i++)
    {
        for (int s = 1; s <= sum; s++)
        {
            // if we can get the sum 's' without the number at index 'i'
            if (DP(i - 1, s))
            {
                DP(i, s) = DP(i - 1, s);
            }
            else if (s >= nums[i])
            {
                // else include the number and see if we can find a subset to
                // get the remaining sum
                DP(i, s) = DP(i - 1, s - nums[i]);
            }
        }
    }

    // the bottom-right corner will have our answer.
    bool result = DP(n - 1, sum);
#undef DP
    free(dp);
    return result;
}
