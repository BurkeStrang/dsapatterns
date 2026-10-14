"""
Given a non-negative integer represented as a string num and an integer k,
delete k digits from num to obtain the smallest possible integer.
Return this minimum possible integer as a string.

Examples

Input: num = "1432219", k = 3
Output: "1219"
Explanation: The digits removed are 4, 3, and 2 forming the new number 1219
which is the smallest.

Input: num = "10200", k = 1
Output: "200"
Explanation: Removing the leading 1 forms the smallest number 200.

Input: num = "1901042", k = 4
Output: "2"
Explanation: Removing 1, 9, 1, and 4 forms the number 2 which is the smallest
possible.

Constraints:
1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
"""


def remove_kdigits(num: str, k: int) -> str:
    # A list of characters works as a stack: append and pop work on its end
    stack: list[str] = []
    for digit in num:
        while k > 0 and stack and stack[-1] > digit:
            stack.pop()
            k -= 1
        stack.append(digit)

    # Truncate the remaining K digits
    while k > 0 and stack:
        stack.pop()
        k -= 1

    # Remove any leading zeros
    result = "".join(stack).lstrip("0")

    # If the string is empty return "0"
    if result == "":
        return "0"
    return result
