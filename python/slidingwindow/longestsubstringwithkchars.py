"""
Given a string, find the length of the longest substring in it with no more
than K distinct characters.
You can assume that K is less than or equal to the length of the given
string.

Example 1:
Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters
is "araa".

Example 2:
Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters
is "aa".

Example 3:
Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters
are "cbbeb" & "bbebi".
Constraints:

1 <= str.length <= 5 * 104
0 <= K <= 50
"""

from collections import defaultdict


def find_length(s: str, k: int) -> int:
    window_start = 0
    max_length = 0
    char_frequency_map: defaultdict[str, int] = defaultdict(int)
    # in the following loop we'll try to extend the range
    # [window_start, window_end]
    for window_end in range(len(s)):
        right_char = s[window_end]
        char_frequency_map[right_char] += 1
        # shrink the sliding window, until we are left with 'k' distinct
        # characters in the frequency map
        while len(char_frequency_map) > k:
            left_char = s[window_start]
            char_frequency_map[left_char] -= 1
            if char_frequency_map[left_char] == 0:
                del char_frequency_map[left_char]
            window_start += 1  # shrink the window
        # remember the maximum length so far
        max_length = max(max_length, window_end - window_start + 1)
    return max_length
