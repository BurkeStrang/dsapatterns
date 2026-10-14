"""
Given a string and a pattern, find all anagrams of the pattern in the given
string.
Every anagram is a permutation of a string.
As we know, when we are not allowed to repeat characters while finding
permutations of a string,
we get  permutations (or anagrams) of a string having  characters. For
example, here are the six anagrams of the string abc:

abc
acb
bac
bca
cab
cba

Write a function to return a list of starting indices of the anagrams of the
pattern in the given string.

Example 1:
Input: str="ppqp", pattern="pq"
Output: [1, 2]
Explanation: The two anagrams of the pattern in the given string are "pq" and
"qp".

Example 2:
Input: str="abbcabc", pattern="abc"
Output: [2, 3, 4]
Explanation: The three anagrams of the pattern in the given string are "bca",
"cab", and "abc".

Constraints:
1 <= s.length, p.length <= 3 * 104
str and pattern consist of lowercase English letters.
"""

from collections import Counter


def find_string_anagrams(s: str, pattern: str) -> list[int]:
    window_start = 0
    matched = 0
    char_frequency_map = Counter(pattern)

    result_indices: list[int] = []
    # our goal is to match all the characters from the map with the current
    # window
    for window_end in range(len(s)):
        right_char = s[window_end]
        if right_char in char_frequency_map:
            # decrement the frequency of the matched character
            char_frequency_map[right_char] -= 1
            if char_frequency_map[right_char] == 0:
                matched += 1

        if matched == len(char_frequency_map):
            # have we found an anagram?
            result_indices.append(window_start)

        if window_end >= len(pattern) - 1:
            # shrink the window
            left_char = s[window_start]
            window_start += 1
            if left_char in char_frequency_map:
                if char_frequency_map[left_char] == 0:
                    # before putting the character back, decrement the
                    # matched count
                    matched -= 1
                # put the character back
                char_frequency_map[left_char] += 1
    return result_indices
