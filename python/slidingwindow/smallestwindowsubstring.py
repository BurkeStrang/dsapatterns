"""
Given a string and a pattern, find the smallest substring in the given string
which has all the character occurrences of the given pattern.

Example 1:
Input: String="aabdec", Pattern="abc"
Output: "abdec"
Explanation: The smallest substring having all characters of the pattern is
"abdec"

Example 2:
Input: String="aabdec", Pattern="abac"
Output: "aabdec"
Explanation: The smallest substring having all characters occurrences of the
pattern is "aabdec"

Example 3:
Input: String="abdbca", Pattern="abc"
Output: "bca"
Explanation: The smallest substring having all characters of the pattern is
"bca".

Example 4:
Input: String="adcad", Pattern="abc"
Output: ""
Explanation: No substring in the given string has all characters of the
pattern
Constraints:

m == String.length
n == Pattern.length
1 <= m, n <= 105
String and Pattern consist of uppercase and lowercase English letters.
"""

from collections import Counter


def find_substring(s: str, pattern: str) -> str:
    window_start = 0
    matched = 0
    min_length = len(s) + 1
    sub_str_start = 0
    char_frequency_map = Counter(pattern)

    # try to extend the range [window_start, window_end]
    for window_end in range(len(s)):
        right_char = s[window_end]
        if right_char in char_frequency_map:
            char_frequency_map[right_char] -= 1
            if char_frequency_map[right_char] >= 0:
                matched += 1

        # shrink the window if we can, finish as soon as we remove a matched
        # character
        while matched == len(pattern):
            if min_length > window_end - window_start + 1:
                min_length = window_end - window_start + 1
                sub_str_start = window_start

            left_char = s[window_start]
            window_start += 1
            if left_char in char_frequency_map:
                # note that we could have redundant matching characters,
                # therefore we'll decrement the matched count only when a
                # useful occurrence of a matched character is going out of the
                # window
                if char_frequency_map[left_char] == 0:
                    matched -= 1
                char_frequency_map[left_char] += 1

    if min_length > len(s):
        return ""
    return s[sub_str_start : sub_str_start + min_length]
