"""
Given a set of numbers that might contain duplicates, find all of its
distinct subsets.

Example 1:
Input: [1, 3, 3]
Output: [], [1], [3], [1,3], [3,3], [1,3,3]

Example 2:
Input: [1, 5, 3, 3]
Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3], [3,3], [1,3,3],
[3,3,5], [1,5,3,3]
"""


def find_dup_subsets(nums: list[int]) -> list[list[int]]:
    # sort the numbers to handle duplicates
    nums.sort()
    subsets: list[list[int]] = [[]]
    # the subsets added in the previous step start here
    previous_step_start = 0
    for i in range(len(nums)):
        start_index = 0
        # if current and the previous elements are same, create new subsets
        # only from the subsets added in the previous step
        if i > 0 and nums[i] == nums[i - 1]:
            start_index = previous_step_start
        previous_step_start = len(subsets)
        for j in range(start_index, previous_step_start):
            # create a new subset from the existing subset and add the
            # current element to it
            subsets.append([*subsets[j], nums[i]])
    return subsets
