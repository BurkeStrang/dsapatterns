#include <string>
#include <vector>

// Given a string, find the total number of palindromic substrings in it.
// Please note we need to find the total number of substrings and not
// subsequences.
//
// Example 1:
// Input: "abdbca"
// Output: 7
// Explanation: Here are the palindromic substrings, "a", "b", "d", "b", "c",
// "a", "bdb".
//
// Example 2:
// Input: = "cddpd"
// Output: 7
// Explanation: Here are the palindromic substrings, "c", "d", "d", "p", "d",
// "dd", "dpd".
//
// Example 3:
// Input: = "pqr"
// Output: 3
// Explanation: Here are the palindromic substrings,"p", "q", "r".

int find_cps(const std::string &st)
{
    int n = std::ssize(st);
    // dp[i][j] will be 'true' if the string from index 'i' to index 'j' is a
    // palindrome
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n));
    int count = 0;

    // every string with one character is a palindrome
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
        count++;
    }
    // abdbca
    // dp is now 6 by 6:
    //         [true,false,false,false,false,false],
    //         [false,true,false,false,false,false],
    //         [false,false,true,false,false,false],
    //         [false,false,false,true,false,false],
    //         [false,false,false,false,true,false],
    //         [false,false,false,false,false,true],

    for (int start_index = n - 1; start_index >= 0; start_index--)
    {
        for (int end_index = start_index + 1; end_index < n; end_index++)
        {
            // if it's a two-character string or if the remaining string is a
            // palindrome too
            if (st[start_index] == st[end_index] &&
                (end_index - start_index == 1 ||
                 dp[start_index + 1][end_index - 1]))
            {
                dp[start_index][end_index] = true;
                count++;
            }
        }
    }

    return count;
}
