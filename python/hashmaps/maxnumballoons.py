"""
Given a string, determine the maximum number of times the word "balloon" can
be formed using the characters from the string.
Each character in the string can be used only once.

Example 1:
Input: "balloonballoon"
Expected Output: 2
Justification: The word "balloon" can be formed twice from the given string.

Example 2:
Input: "bbaall"
Expected Output: 0
Justification: The word "balloon" cannot be formed from the given string as
we are missing the character 'o' twice.

Example 3:
Input: "balloonballoooon"
Expected Output: 2
Justification: The word "balloon" can be formed twice, even though there are
extra 'o' characters.

Constraints:
1 <= text.length <= 104
text consists of lower case English letters only.
"""

from collections import Counter


def max_number_of_balloons(text: str) -> int:
    freq = Counter(text)

    min_result = len(text)
    for letter in "balon":
        count = freq[letter]
        if letter in ("l", "o"):
            min_result = min(min_result, count // 2)
        else:
            min_result = min(min_result, count)
    return min_result
