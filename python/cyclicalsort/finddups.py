"""
We are given an unsorted array containing n numbers taken from the range 1 to
n.
The array has some numbers appearing twice,
find all these duplicate numbers using constant space.

Example 1:
Input: [3, 4, 4, 5, 5]
Output: [4, 5]

Example 2:
Input: [5, 4, 7, 2, 3, 5, 3]
Output: [3, 5]
Constraints:

nums.length == n
1 <= n <=
1 <= nums[i] <= n
Each element in nums appears once or twice.
"""


def find_dups(nums: list[int]) -> list[int]:
    i = 0
    while i < len(nums):
        j = nums[i] - 1
        if nums[i] != nums[j]:
            # The current element is not in its correct position: swap it with
            # the element at its correct position.
            nums[i], nums[j] = nums[j], nums[i]
        else:
            # Move to the next element if the current element is already in
            # its correct position.
            i += 1

    duplicate_numbers: list[int] = []
    for k in range(len(nums)):
        # Elements that are not in their correct positions are duplicates.
        if nums[k] != k + 1:
            duplicate_numbers.append(nums[k])
    return duplicate_numbers
