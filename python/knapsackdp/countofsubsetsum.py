"""
Given a set of positive numbers,
find the total number of subsets whose sum is equal to a given number ‘S’.

Example 1:
Input: {1, 1, 2, 3}, S=4
Output: 3
The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
Note that we have two similar sets {1, 3}, because we have two '1' in our
input.

Example 2:
Input: {1, 2, 7, 1, 5}, S=9
Output: 3
The given set has '3' subsets whose sum is '9': {2, 7}, {1, 7, 1}, {1, 2, 1,
5}
"""


def count_subsets_recursive(
    num: list[int], target: int, current_index: int
) -> int:
    # base checks
    if target == 0:
        return 1
    if current_index >= len(num):
        return 0

    # recursive call after selecting the number at the current_index
    # if the number at current_index exceeds the target, we shouldn't process
    # this
    sum1 = 0
    if num[current_index] <= target:
        sum1 = count_subsets_recursive(
            num, target - num[current_index], current_index + 1
        )

    # recursive call after excluding the number at the current_index
    sum2 = count_subsets_recursive(num, target, current_index + 1)

    return sum1 + sum2


def count_subsets(num: list[int], target: int) -> int:
    return count_subsets_recursive(num, target, 0)
