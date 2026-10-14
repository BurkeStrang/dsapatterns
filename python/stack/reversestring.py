"""
Given a string, write a function that uses a stack to reverse the string. The
function should return the reversed string.

Example 1:
Input: "Hello, World!"
Output: "!dlroW ,olleH"

Example 2:
Input: "OpenAI"
Output: "IAnepO"

Example 3:
Input: "Stacks are fun!"
Output: "!nuf era skcatS"
Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
"""


def reverse_string(text: str) -> str:
    reverse_list: list[str] = []
    stack = list(text)

    # pop all letters from stack to reverse_list
    while stack:
        reverse_list.append(stack.pop())

    return "".join(reverse_list)
