"""
Given two strings containing backspaces (identified by the character ‘#’),
check if the two strings are equal.

Example 1:

Input: str1="xy#z", str2="xzz#"
Output: true
Explanation: After applying backspaces the strings become "xz" and "xz"
respectively.
Example 2:

Input: str1="xy#z", str2="xyz#"
Output: false
Explanation: After applying backspaces the strings become "xz" and "xy"
respectively.
Example 3:

Input: str1="xp#", str2="xyz##"
Output: true
Explanation: After applying backspaces the strings become "x" and "x"
respectively.
In "xyz##", the first '#' removes the character 'z' and the second '#'
removes the character 'y'.
Example 4:

Input: str1="xywrrmp", str2="xywrrmu#p"
Output: true
Explanation: After applying backspaces the strings become "xywrrmp" and
"xywrrmp" respectively.
Constraints:

1 <= str1.length, str2.length <= 200
str1 and str2 only contain lowercase letters and '#' characters.
"""


def get_next_valid_char_index(s: str, index: int) -> int:
    """Returns the index of the next character that is not deleted by a
    backspace, looking from index towards the start; -1 once we have gone past
    the start."""
    backspace_count = 0
    while index >= 0:
        if s[index] == "#":
            # found a backspace character
            backspace_count += 1
        elif backspace_count > 0:
            # a non-backspace character
            backspace_count -= 1
        else:
            break
        index -= 1  # skip a backspace or a valid character
    return index


def compare(str1: str, str2: str) -> bool:
    # the next character to look at in each string, counting from the end
    index1 = len(str1) - 1
    index2 = len(str2) - 1
    while index1 >= 0 or index2 >= 0:
        i1 = get_next_valid_char_index(str1, index1)
        i2 = get_next_valid_char_index(str2, index2)
        if i1 < 0 and i2 < 0:
            return True  # reached the end of both the strings
        if i1 < 0 or i2 < 0:
            return False  # reached the end of one of the strings
        if str1[i1] != str2[i2]:
            return False  # check if the characters are equal
        index1 = i1 - 1
        index2 = i2 - 1
    return True
