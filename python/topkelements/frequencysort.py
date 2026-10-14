"""
Given a string, sort it based on the decreasing frequency of its characters.

Example 1:
Input: "Programming"
Output: "rrggmmPiano"
Explanation: 'r', 'g', and 'm' appeared twice, so they need to appear before
any other character.

Example 2:
Input: "abcbab"
Output: "bbbaac"
Explanation: 'b' appeared three times, 'a' appeared twice, and 'c' appeared
only once.
"""

from collections import Counter


def sort_character_by_frequency(s: str) -> str:
    # Find the frequency of each character
    character_frequency_map = Counter(s)

    # Sort the character-frequency pairs by frequency in descending order
    character_frequency_pairs = sorted(
        character_frequency_map.items(), key=lambda pair: pair[1], reverse=True
    )

    # Build a string, appending the most occurring characters first
    return "".join(
        character * frequency
        for character, frequency in character_frequency_pairs
    )
