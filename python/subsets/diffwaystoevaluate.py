"""
Given an expression containing digits and operations (+, -, *),
find all possible ways in which the expression can be evaluated
by grouping the numbers and operators using parentheses.

Example 1:
Input: "1+2*3"
Output: 7, 9
Explanation:
  1+(2*3) => 7
  (1+2)*3 => 9

Example 2:
Input: "2*3-4-5"
Output: 8, -12, 7, -7, -3
Explanation:
  2*(3-(4-5)) => 8
  2*(3-4-5) => -12
  2*3-(4-5) => 7
  2*(3-4)-5 => -7
  (2*3)-4-5 => -3
"""


def diff_ways_to_evaluate_expression(expression: str) -> list[int]:
    result: list[int] = []
    # base case: if the input string is a number, parse and add it to output.
    if not any(op in expression for op in "+-*"):
        result.append(int(expression))
        return result

    for i, char in enumerate(expression):
        if char.isdigit():
            continue
        # break the equation here into two parts and make recursively calls
        left_parts = diff_ways_to_evaluate_expression(expression[:i])
        right_parts = diff_ways_to_evaluate_expression(expression[i + 1 :])
        for part1 in left_parts:
            for part2 in right_parts:
                if char == "+":
                    result.append(part1 + part2)
                elif char == "-":
                    result.append(part1 - part2)
                elif char == "*":
                    result.append(part1 * part2)
    return result
