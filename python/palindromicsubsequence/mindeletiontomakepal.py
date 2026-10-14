"""
Given a string,
find the minimum number of characters that we can remove to make it a
palindrome.

Example 1:
Input: "abdbca"
Output: 1
Explanation: By removing "c", we get a palindrome "abdba".

Example 2:
Input: = "cddpd"
Output: 2
Explanation: Deleting "cp", we get a palindrome "ddd".

Example 3:
Input: = "pqr"
Output: 2
Explanation: We have to remove any two characters to get a palindrome, e.g.
if we
remove "pq", we get palindrome "r".
"""


def find_lps_len(st: str) -> int:
    n = len(st)
    if n == 0:
        return 0

    # dp[i][j] stores the length of LPS from index 'i' to index 'j'
    dp = [[0] * n for _ in range(n)]

    # every sequence with one element is a palindrome of length 1
    for i in range(n):
        dp[i][i] = 1

    for start_index in range(n - 1, -1, -1):
        for end_index in range(start_index + 1, n):
            if st[start_index] == st[end_index]:
                # case 1: elements at the beginning and the end are the same
                dp[start_index][end_index] = (
                    2 + dp[start_index + 1][end_index - 1]
                )
            else:
                # case 2: skip one element either from the beginning or the
                # end
                dp[start_index][end_index] = max(
                    dp[start_index + 1][end_index],
                    dp[start_index][end_index - 1],
                )

    return dp[0][n - 1]


def find_minimum_deletions(st: str) -> int:
    # subtracting the length of Longest Palindromic Subsequence from the
    # length of the input string to get minimum number of deletions
    return len(st) - find_lps_len(st)
