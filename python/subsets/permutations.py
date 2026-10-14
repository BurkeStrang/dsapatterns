"""
Given a set of distinct numbers, find all of its permutations.

Example 1:
Input: [1,3,5]
Output: [1,3,5], [1,5,3], [3,1,5], [3,5,1], [5,1,3], [5,3,1]
"""

from collections import deque


def find_permutations(nums: list[int]) -> list[list[int]]:
    result: list[list[int]] = []
    permutations: deque[list[int]] = deque([[]])
    for current_number in nums:
        # we will take all existing permutations and add the current number
        # to create new permutations
        for _ in range(len(permutations)):
            old_permutation = permutations.popleft()
            # create a new permutation by adding the current number at every
            # position
            for j in range(len(old_permutation) + 1):
                new_permutation = list(old_permutation)
                new_permutation.insert(j, current_number)
                if len(new_permutation) == len(nums):
                    result.append(new_permutation)
                else:
                    permutations.append(new_permutation)
    return result
