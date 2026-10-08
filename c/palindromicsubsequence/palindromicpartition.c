#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Given a string, we want to cut it into pieces such that each piece is a
// palindrome.
// Write a function to return the minimum number of cuts needed.
//
// Example 1:
// Input: "abdbca"
// Output: 3
// Explanation: Palindrome pieces are "a", "bdb", "c", "a".
//
// Example 2:
// Input: = "cddpd"
// Output: 2
// Explanation: Palindrome pieces are "c", "d", "dpd".
//
// Example 3:
// Input: = "pqr"
// Output: 2
// Explanation: Palindrome pieces are "p", "q", "r".
//
// Example 4:
// Input: = "pp"
// Output: 0
// Explanation: We do not need to cut, as "pp" is a palindrome.
// Constraints:
//
// 1 <= st.length <= 16
// s contains only lowercase English letters.

int find_mpp_cuts
(
    const char *st
)
{
    int n = (int)strlen(st);
    if (n == 0)
    {
        return 0;
    }
    // IS_PALINDROME(i, j) will be 'true' if the string from index 'i' to
    // index 'j' is a palindrome
    bool *is_palindrome = calloc((size_t)n * (size_t)n, sizeof(bool));
#define IS_PALINDROME(i, j) is_palindrome[(i) * n + (j)]

    // every string with one character is a palindrome
    for (int i = 0; i < n; i++)
    {
        IS_PALINDROME(i, i) = true;
    }

    // populate the is_palindrome table
    for (int start_index = n - 1; start_index >= 0; start_index--)
    {
        for (int end_index = start_index + 1; end_index < n; end_index++)
        {
            if (st[start_index] == st[end_index])
            {
                // if it's a two-character string or if the remaining string
                // is a palindrome too
                if (end_index - start_index == 1 ||
                    IS_PALINDROME(start_index + 1, end_index - 1))
                {
                    IS_PALINDROME(start_index, end_index) = true;
                }
            }
        }
    }

    // now let's populate the second table, every index in 'cuts' stores the
    // minimum cuts needed for the substring from that index till the end
    int *cuts = calloc((size_t)n, sizeof(int));
    for (int start_index = n - 1; start_index >= 0; start_index--)
    {
        int min_cuts = n; // maximum cuts
        for (int end_index = n - 1; end_index >= start_index; end_index--)
        {
            if (IS_PALINDROME(start_index, end_index))
            {
                // we can cut here as we got a palindrome
                // also, we don't need any cut if the whole substring is a
                // palindrome
                if (end_index == n - 1)
                {
                    min_cuts = 0;
                }
                else if (1 + cuts[end_index + 1] < min_cuts)
                {
                    min_cuts = 1 + cuts[end_index + 1];
                }
            }
        }
        cuts[start_index] = min_cuts;
    }

    int result = cuts[0];
#undef IS_PALINDROME
    free(cuts);
    free(is_palindrome);
    return result;
}
