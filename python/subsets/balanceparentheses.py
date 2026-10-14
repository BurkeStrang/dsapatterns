"""
For a given number 'num', write a function to generate all combinations of
'num' pairs of balanced parentheses.

Example 1:
Input: num=2
Output: (()), ()()

Example 2:
Input: num=3
Output: ((())), (()()), (())(), ()(()), ()()()
"""

from collections import deque
from dataclasses import dataclass


@dataclass
class ParenthesesString:
    text: str
    open_count: int  # open parentheses count
    close_count: int  # close parentheses count


def generate_valid_parentheses(num: int) -> list[str]:
    result: list[str] = []
    queue = deque([ParenthesesString("", 0, 0)])
    while queue:
        ps = queue.popleft()
        # if we've reached the maximum number of open and close parentheses,
        # add to result
        if ps.open_count == num and ps.close_count == num:
            result.append(ps.text)
        else:
            # if we can add an open parentheses, add it
            if ps.open_count < num:
                queue.append(
                    ParenthesesString(
                        ps.text + "(", ps.open_count + 1, ps.close_count
                    )
                )

            # if we can add a close parentheses, add it
            if ps.open_count > ps.close_count:
                queue.append(
                    ParenthesesString(
                        ps.text + ")", ps.open_count, ps.close_count + 1
                    )
                )
    return result
