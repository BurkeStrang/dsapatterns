#include <string.h>

// Given a sequence, find the length of its Longest Palindromic Subsequence
// (LPS).
// In a palindromic subsequence, elements read the same backward and forward.
// A subsequence is a sequence that can be derived from another sequence
// by deleting some or no elements without changing the order of the remaining
// elements.
//
// Example 1:
// Input: "abdbca"
// Output: 5
// Explanation: LPS is "abdba".
//
// Example 2:
// Input: = "cddpd"
// Output: 3
// Explanation: LPS is "ddd".
//
// Example 3:
// Input: = "pqr"
// Output: 1
// Explanation: LPS could be "p", "q" or "r".

int find_lps_length_recursive
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
        return 2 +
               find_lps_length_recursive(st, start_index + 1, end_index - 1);
    }

    int c1 = find_lps_length_recursive(st, start_index + 1, end_index);
    int c2 = find_lps_length_recursive(st, start_index, end_index - 1);
    if (c1 > c2)
    {
        return c1;
    }
    return c2;
}

int find_lps_length
(
    const char *st
)
{
    return find_lps_length_recursive(st, 0, (int)strlen(st) - 1);
}
