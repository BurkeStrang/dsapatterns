"""
Given an unsorted array containing numbers, find the smallest missing
positive number in it.

Note: Positive numbers start from '1'.

Example 1:

Input: [-3, 1, 5, 4, 2]
Output: 3
Explanation: The smallest missing positive number is '3'
Example 2:

Input: [3, -2, 0, 1, 2]
Output: 4
Example 3:

Input: [3, 2, 5, 1]
Output: 4
Example 4:

Input: [33, 37, 5]
Output: 1
Constraints:

1 <= nums.length <=
-231 <= nums[i] <= 231 - 1
"""


def find_mis(nums: list[int]) -> int:
    n = len(nums)
    i = 0
    # Rearrange the elements to place each positive integer at its correct
    # index. Negative numbers and numbers greater than the array size are
    # ignored.
    while i < n:
        j = nums[i] - 1
        if 0 <= j < n and nums[i] != nums[j]:
            nums[i], nums[j] = nums[j], nums[i]
        else:
            i += 1

    # Find the first index where the element does not match its expected
    # positive value.
    for j in range(n):
        if nums[j] != j + 1:
            return j + 1

    # If all elements from 1 to n are present, return n + 1.
    return n + 1
