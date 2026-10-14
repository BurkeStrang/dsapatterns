"""
Numbers can be regarded as the product of their factors.
For example, 8 = 2 x 2 x 2 = 2 x 4.
Given an integer n,
return all possible combinations of its factors.
You may return the answer in any order.

Example 1:
Input: n = 8
Output: [[2, 2, 2], [2, 4]]

Example 2:
Input: n = 20
Output: [[2, 2, 5], [2, 10], [4, 5]]

Constraints:
2 <= n <= 107
"""


def get_all_factors(
    n: int, start: int, curr: list[int], result: list[list[int]]
) -> None:
    # go up to the square root of 'n'
    i = start
    while i * i <= n:
        if n % i == 0:
            curr.append(i)
            # 'i' and 'n / i' finish off a combination
            result.append([*curr, n // i])
            # keep 'i' and break 'n / i' down further
            get_all_factors(n // i, i, curr, result)
            curr.pop()
        i += 1


def get_factors(n: int) -> list[list[int]]:
    result: list[list[int]] = []
    get_all_factors(n, 2, [], result)
    return result
