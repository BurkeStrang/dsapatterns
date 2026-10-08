#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

int find_cps
(
    const char *st
)
{
    int n = (int)strlen(st);
    // DP(i, j) will be 'true' if the string from index 'i' to index 'j' is a
    // palindrome
    bool *dp = calloc((size_t)n * (size_t)n + 1, sizeof(bool));
#define DP(i, j) dp[(i) * n + (j)]
    int count = 0;

    // every string with one character is a palindrome
    for (int i = 0; i < n; i++)
    {
        DP(i, i) = true;
        count++;
    }

    // abdbca
    // dp (6 x 6) = [
    //         [true,false,false,false,false,false],
    //         [false,true,false,false,false,false],
    //         [false,false,true,false,false,false],
    //         [false,false,false,true,false,false],
    //         [false,false,false,false,true,false],
    //         [false,false,false,false,false,true],
    // ]

    for (int start_index = n - 1; start_index >= 0; start_index--)
    {
        for (int end_index = start_index + 1; end_index < n; end_index++)
        {
            if (st[start_index] == st[end_index])
            {
                // if it's a two-character string or if the remaining string
                // is a palindrome too
                if (end_index - start_index == 1 ||
                    DP(start_index + 1, end_index - 1))
                {
                    DP(start_index, end_index) = true;
                    count++;
                }
            }
        }
    }

#undef DP
    free(dp);
    return count;
}
