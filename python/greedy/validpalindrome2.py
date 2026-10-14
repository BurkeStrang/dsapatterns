"""
Given string s,
determine whether it's possible to make a given string palindrome by removing
at most one character.
A palindrome is a word or phrase that reads the same backward as forward.

Example 1:
Input: "racecar"
Expected Output: true
Justification: The string is already a palindrome, so no removals are needed.

Example 2:
Input: "abeccdeba"
Expected Output: true
Justification: Removing the character 'd' forms the palindrome "abccba".

Example 3:
Input: "abcdef"
Expected Output: false
Justification: No single character removal will make this string a
palindrome.
"""


def is_palindrome(text: str, left: int, right: int) -> bool:
    """Checks if a substring is a palindrome."""
    while left < right:
        if text[left] != text[right]:
            return False
        left += 1
        right -= 1
    return True


def is_palindrome_possible(text: str) -> bool:
    left = 0
    right = len(text) - 1
    while left < right:
        if text[left] != text[right]:
            # Check if either substring is a palindrome
            return is_palindrome(text, left + 1, right) or is_palindrome(
                text, left, right - 1
            )
        left += 1
        right -= 1
    return True  # String is already a palindrome
