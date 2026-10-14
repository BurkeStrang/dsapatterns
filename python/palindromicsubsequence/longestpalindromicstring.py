"""
Given a string, find the length of its Longest Palindromic Substring (LPS).
In a palindromic string, elements read the same backward and forward.

Example 1:
Input: "abdbca"
Output: 3
Explanation: LPS is "bdb".

Example 2:
Input: = "cddpd"
Output: 3
Explanation: LPS is "dpd".

Example 3:
Input: = "pqr"
Output: 1
Explanation: LPS could be "p", "q" or "r".
"""


def palindrome_length(st: str, start_index: int, end_index: int) -> int:
    if start_index > end_index:
        return 0

    # every string with one character is a palindrome
    if start_index == end_index:
        return 1

    # case 1: elements at the beginning and the end are the same
    if st[start_index] == st[end_index]:
        remaining_length = end_index - start_index - 1
        # check if the remaining string is also a palindrome
        if remaining_length == palindrome_length(
            st, start_index + 1, end_index - 1
        ):
            return remaining_length + 2

    # case 2: skip one character either from the beginning or the end
    c1 = palindrome_length(st, start_index + 1, end_index)
    c2 = palindrome_length(st, start_index, end_index - 1)
    return max(c1, c2)


def find_lp_string_length(st: str) -> int:
    return palindrome_length(st, 0, len(st) - 1)
