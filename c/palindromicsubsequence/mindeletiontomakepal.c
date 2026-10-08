#include <stdlib.h>
#include <string.h>

// Given a string,
// find the minimum number of characters that we can remove to make it a
// palindrome.
//
// Example 1:
// Input: "abdbca"
// Output: 1
// Explanation: By removing "c", we get a palindrome "abdba".
//
// Example 2:
// Input: = "cddpd"
// Output: 2
// Explanation: Deleting "cp", we get a palindrome "ddd".
//
// Example 3:
// Input: = "pqr"
// Output: 2
// Explanation: We have to remove any two characters to get a palindrome, e.g.
// if we
// remove "pq", we get palindrome "r".

int find_lps_len
(
    const char *st
)
{
    int n = (int)strlen(st);
    if (n == 0)
    {
        return 0;
    }
    // dp is a table of n rows and n columns; DP(i, j) is one of its cells
    int *dp = calloc((size_t)n * (size_t)n, sizeof(int));
#define DP(i, j) dp[(i) * n + (j)]
    for (int i = 0; i < n; i++)
    {
        DP(i, i) = 1;
    }

    for (int start_index = n - 1; start_index >= 0; start_index--)
    {
        for (int end_index = start_index + 1; end_index < n; end_index++)
        {
            if (st[start_index] == st[end_index])
            {
                DP(start_index, end_index) =
                    2 + DP(start_index + 1, end_index - 1);
            }
            else
            {
                int skip_start = DP(start_index + 1, end_index);
                int skip_end = DP(start_index, end_index - 1);
                DP(start_index, end_index) =
                    skip_start > skip_end ? skip_start : skip_end;
            }
        }
    }

    int result = DP(0, n - 1);
#undef DP
    free(dp);
    return result;
}

int find_minimum_deletions
(
    const char *st
)
{
    return (int)strlen(st) - find_lps_len(st);
}
