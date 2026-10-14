"""
Given two arrays, find if the second one is a subarray of the first: its
numbers appear in the first array next to each other and in the same order.
"""


def is_subarray(nums: list[int], sub: list[int]) -> bool:
    return any(
        nums[i : i + len(sub)] == sub for i in range(len(nums) - len(sub) + 1)
    )
