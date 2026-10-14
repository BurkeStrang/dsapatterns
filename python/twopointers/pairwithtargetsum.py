"""
Given a sorted array and a target sum, find the indices of a pair of
numbers that add up to the target. Returns None if there is no such pair.
"""


def search(arr: list[int], target_sum: int) -> tuple[int, int] | None:
    left = 0
    right = len(arr) - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == target_sum:
            return (left, right)
        if current_sum < target_sum:
            left += 1
        else:
            right -= 1
    return None
