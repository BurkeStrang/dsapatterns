#include <algorithm>
#include <string>

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

int find_lps_length_recursive(const std::string &st, int start_index,
                              int end_index)
{
    if (start_index > end_index)
    {
        return 0;
    }

    // every sequence with one element is a palindrome of length 1
    if (start_index == end_index)
    {
        return 1;
    }

    // case 1: elements at the beginning and the end are the same
    if (st[start_index] == st[end_index])
    {
        return 2 +
               find_lps_length_recursive(st, start_index + 1, end_index - 1);
    }

    // case 2: skip one element either from the beginning or the end
    int c1 = find_lps_length_recursive(st, start_index + 1, end_index);
    int c2 = find_lps_length_recursive(st, start_index, end_index - 1);
    return std::max(c1, c2);
}

int find_lps_length(const std::string &st)
{
    return find_lps_length_recursive(st, 0, std::ssize(st) - 1);
}
