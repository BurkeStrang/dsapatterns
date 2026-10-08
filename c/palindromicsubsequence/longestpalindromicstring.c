#include <string.h>

// Given a string, find the length of its Longest Palindromic Substring (LPS).
// In a palindromic string, elements read the same backward and forward.
//
// Example 1:
// Input: "abdbca"
// Output: 3
// Explanation: LPS is "bdb".
//
// Example 2:
// Input: = "cddpd"
// Output: 3
// Explanation: LPS is "dpd".
//
// Example 3:
// Input: = "pqr"
// Output: 1
// Explanation: LPS could be "p", "q" or "r".

int palindrome_length
(
    const char *st,
    int start_index,
    int end_index
)
{
    if (start_index > end_index)
    {
        return 0;
    }

    if (start_index == end_index)
    {
        return 1;
    }

    if (st[start_index] == st[end_index])
    {
        int remaining_length = end_index - start_index - 1;
        if (remaining_length ==
            palindrome_length(st, start_index + 1, end_index - 1))
        {
            return remaining_length + 2;
        }
    }

    int c1 = palindrome_length(st, start_index + 1, end_index);
    int c2 = palindrome_length(st, start_index, end_index - 1);
    if (c1 > c2)
    {
        return c1;
    }
    return c2;
}

int find_lp_string_length
(
    const char *st
)
{
    return palindrome_length(st, 0, (int)strlen(st) - 1);
}
