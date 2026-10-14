#include <algorithm>
#include <string>
#include <vector>

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

int find_lps_len(const std::string &st)
{
    int n = std::ssize(st);
    if (n == 0)
    {
        return 0;
    }

    // dp[i][j] stores the length of LPS from index 'i' to index 'j'
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));

    // every sequence with one element is a palindrome of length 1
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    for (int start_index = n - 1; start_index >= 0; start_index--)
    {
        for (int end_index = start_index + 1; end_index < n; end_index++)
        {
            if (st[start_index] == st[end_index])
            {
                // case 1: elements at the beginning and the end are the same
                dp[start_index][end_index] =
                    2 + dp[start_index + 1][end_index - 1];
            }
            else
            {
                // case 2: skip one element either from the beginning or the
                // end
                dp[start_index][end_index] =
                    std::max(dp[start_index + 1][end_index],
                             dp[start_index][end_index - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int find_minimum_deletions(const std::string &st)
{
    // subtracting the length of Longest Palindromic Subsequence from the
    // length of the input string to get minimum number of deletions
    return std::ssize(st) - find_lps_len(st);
}
