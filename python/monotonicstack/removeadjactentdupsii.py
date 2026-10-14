"""
You are given a string s and an integer k. Your task is to remove groups of
identical,
consecutive characters from the string such that each group has exactly k
characters.
The removal of groups should continue until it's no longer possible to make
any more removals.
The result should be the final version of the string after all possible
removals have been made.

Examples

Input: s = "abbbaaca", k = 3
Output: "ca"
Explanation: First, we remove "bbb" to get "aaaca". Then, we remove "aaa" to
get "ca".

Input: s = "abbaccaa", k = 3
Output: "abbaccaa"
Explanation: There are no instances of 3 adjacent characters being the same.

Input: s = "abbacccaa", k = 3
Output: "abb"
Explanation: First, we remove "ccc" to get "abbaaa". Then, we remove "aaa" to
get "abb".

Constraints:
1 <= s.length <= 105
2 <= k <= 104
s only contains lowercase English letters.
"""

from dataclasses import dataclass


@dataclass
class StackElement:
    c: str
    count: int


def remove_duplicates_ii(s: str, k: int) -> str:
    # An empty stack to track characters and their counts.
    stack: list[StackElement] = []

    # Iterate through each character in the input string 's'.
    for c in s:
        if stack and stack[-1].c == c:
            # If the stack is not empty and the current character is the same
            # as the top of the stack, increment the count of the top
            # character in the stack.
            stack[-1].count += 1
        else:
            # Otherwise, push a new character-count pair onto the stack.
            stack.append(StackElement(c, 1))

        # If the count of the top character in the stack reaches 'k'.
        if stack[-1].count == k:
            stack.pop()  # Remove it from the stack.

    # Rebuild the string from the characters remaining in the stack.
    return "".join(element.c * element.count for element in stack)
