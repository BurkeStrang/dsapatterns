"""
Given a string s and an array of words words.
Break string s into multiple non-overlapping substrings such that each
substring should be part of the words.
There are some characters left which are not part of any substring.
Return the minimum number of remaining characters in s,
which are not part of any substring after string break-up.

Example 1:
Input: s = "amazingracecar", dictionary = ["race", "car"]
Expected Output: 7
Justification: The string s can be rearranged to form "racecar", leaving 'a',
'm', 'a', 'z', 'i', 'n', 'g' as extra.

Example 2:
Input: s = "bookkeeperreading", dictionary = ["keep", "read"]
Expected Output: 9
Justification: The words "keep" and "read" can be formed from s, but 'b',
'o', 'o', 'k', 'e', 'r', 'i', 'n', 'g' are extra.

Example 3:
Input: s = "thedogbarksatnight", dictionary = ["dog", "bark", "night"]
Expected Output: 6
Justification: The words "dog", "bark", and "night" can be formed, leaving
't', 'h', 'e', 's', 'a', 't' as extra characters.

Constraints:
1 <= str.length <= 50
1 <= dictionary.length <= 50
1 <= dictionary[i].length <= 50
dictionary[i] and s consists of only lowercase English letters
dictionary contains distinct words
"""


def solve(
    index: int, s: str, word_set: set[str], memo: list[int | None]
) -> int:
    # Base case: when we reach the end of the string
    if index == len(s):
        return 0

    # Return the cached result if already computed
    cached = memo[index]
    if cached is not None:
        return cached

    # Count the current character as an extra character
    min_extra = solve(index + 1, s, word_set, memo) + 1

    # Try forming substrings starting from the current index
    for end in range(index, len(s)):
        substring = s[index : end + 1]
        # Check if the substring is in the dictionary
        if substring in word_set:
            # Update minimum extra characters
            min_extra = min(min_extra, solve(end + 1, s, word_set, memo))

    # Store the result in the memo and return
    memo[index] = min_extra
    return min_extra


def min_extra_char(s: str, dictionary: list[str]) -> int:
    # No answer has been worked out yet, for any index
    memo: list[int | None] = [None] * len(s)
    # Populate a set with the dictionary words
    word_set = set(dictionary)
    return solve(0, s, word_set, memo)
