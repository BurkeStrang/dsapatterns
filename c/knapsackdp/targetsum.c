#include <stdlib.h>

// You are given a set of positive numbers and a target sum ‘S’.
// Each number should be assigned either a ‘+’ or ‘-’ sign.
// We need to find the total ways to assign symbols to make the sum of the
// numbers equal to the target ‘S’.
//
// Example 1:
// Input: {1, 1, 2, 3}, S=1
// Output: 3
// Explanation: The given set has '3' ways to make a sum of '1': {+1-1-2+3} &
// {-1+1-2+3} & {+1+1+2-3}
//
// Example 2:
// Input: {1, 2, 7, 1}, S=9
// Output: 2
// Explanation: The given set has '2' ways to make a sum of '9': {+1+2+7-1} &
// {-1+2+7+1}

int count_sets
(
    const int *num,
    int n,
    int sum
)
{
    // dp is a table of n rows and sum+1 columns; DP(i, s) is one of its cells
    int cols = sum + 1;
    int *dp = calloc((size_t)n * (size_t)cols, sizeof(int));
#define DP(i, s) dp[(i) * cols + (s)]

    for (int i = 0; i < n; i++)
    {
        DP(i, 0) = 1;
    }

    for (int s = 1; s <= sum; s++)
    {
        if (num[0] == s)
        {
            DP(0, s) = 1;
        }
        else
        {
            DP(0, s) = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int s = 1; s <= sum; s++)
        {
            DP(i, s) = DP(i - 1, s);
            if (s >= num[i])
            {
                DP(i, s) += DP(i - 1, s - num[i]);
            }
        }
    }

    int result = DP(n - 1, sum);
#undef DP
    free(dp);
    return result;
}

int find_target_subsets
(
    const int *num,
    int num_len,
    int target
)
{
    int total_sum = 0;
    for (int i = 0; i < num_len; i++)
    {
        total_sum += num[i];
    }

    if (total_sum < target || (target + total_sum) % 2 == 1)
    {
        return 0;
    }

    return count_sets(num, num_len, (target + total_sum) / 2);
}
