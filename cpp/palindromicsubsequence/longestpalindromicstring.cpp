#include <algorithm>
#include <string>

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

int palindrome_length(const std::string &st, int start_index, int end_index)
{
    if (start_index > end_index)
    {
        return 0;
    }

    // every string with one character is a palindrome
    if (start_index == end_index)
    {
        return 1;
    }

    // case 1: elements at the beginning and the end are the same
    if (st[start_index] == st[end_index])
    {
        int remaining_length = end_index - start_index - 1;
        // check if the remaining string is also a palindrome
        if (remaining_length ==
            palindrome_length(st, start_index + 1, end_index - 1))
        {
            return remaining_length + 2;
        }
    }

    // case 2: skip one character either from the beginning or the end
    int c1 = palindrome_length(st, start_index + 1, end_index);
    int c2 = palindrome_length(st, start_index, end_index - 1);
    return std::max(c1, c2);
}

int find_lp_string_length(const std::string &st)
{
    return palindrome_length(st, 0, std::ssize(st) - 1);
}
