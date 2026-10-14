"""
Given a string, find the total number of palindromic substrings in it.
Please note we need to find the total number of substrings and not
subsequences.

Example 1:
Input: "abdbca"
Output: 7
Explanation: Here are the palindromic substrings, "a", "b", "d", "b", "c",
"a", "bdb".

Example 2:
Input: = "cddpd"
Output: 7
Explanation: Here are the palindromic substrings, "c", "d", "d", "p", "d",
"dd", "dpd".

Example 3:
Input: = "pqr"
Output: 3
Explanation: Here are the palindromic substrings,"p", "q", "r".
"""


def find_cps(st: str) -> int:
    n = len(st)
    # dp[i][j] will be 'true' if the string from index 'i' to index 'j' is a
    # palindrome
    dp = [[False] * n for _ in range(n)]
    count = 0

    # every string with one character is a palindrome
    for i in range(n):
        dp[i][i] = True
        count += 1

    # abdbca
    # dp is now 6 by 6:
    #         [true,false,false,false,false,false],
    #         [false,true,false,false,false,false],
    #         [false,false,true,false,false,false],
    #         [false,false,false,true,false,false],
    #         [false,false,false,false,true,false],
    #         [false,false,false,false,false,true],

    for start_index in range(n - 1, -1, -1):
        for end_index in range(start_index + 1, n):
            # if it's a two-character string or if the remaining string is a
            # palindrome too
            if st[start_index] == st[end_index] and (
                end_index - start_index == 1
                or dp[start_index + 1][end_index - 1]
            ):
                dp[start_index][end_index] = True
                count += 1

    return count
