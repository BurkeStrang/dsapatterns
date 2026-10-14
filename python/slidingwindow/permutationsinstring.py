"""
Given a string and a pattern, find out if the string contains any permutation
of the pattern.

Permutation is defined as the re-arranging of the characters of the string.
For example, “abc” has the following six permutations:

abc
acb
bac
bca
cab
cba
If a string has ‘n’ distinct characters, it will have n! permutations.

Example 1:
Input: str="oidbcaf", pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given
pattern.

Example 2:
Input: str="odicf", pattern="dc"
Output: false
Explanation: No permutation of the pattern is present in the given string as
a substring.

Example 3:
Input: str="bcdxabcdy", pattern="bcdyabcdx"
Output: true
Explanation: Both the string and the pattern are a permutation of each other.

Example 4:
Input: str="aaacb", pattern="abc"
Output: true
Explanation: The string contains "acb" which is a permutation of the given
pattern.
Constraints:

1 <= str.length, pat.length <= 104
str and pat consist of lowercase English letters.
"""


def equal_perm(str1: str, str2: str) -> bool:
    checker = [0] * 26
    for index in range(len(str2)):
        checker[ord(str1[index]) - ord("a")] += 1
        checker[ord(str2[index]) - ord("a")] -= 1
    return all(value == 0 for value in checker)


def find_permutation(s: str, pattern: str) -> bool:
    start = 0
    end = len(pattern)
    while end <= len(s):
        if equal_perm(s[start:end], pattern):
            return True
        start += 1
        end += 1
    return False
