"""
Given an unsorted array of numbers, find the ‘K’ largest numbers in it.

Example 1:
Input: [3, 1, 5, 12, 2, 11], K = 3
Output: [5, 12, 11]

Example 2:
Input: [5, 12, 11, -1, 12], K = 3
Output: [12, 11, 12]
"""

import heapq


def find_k_largest_numbers(nums: list[int], k: int) -> list[int]:
    # a min heap of the 'K' largest numbers seen so far
    min_heap: list[int] = []

    # put first 'K' numbers in the min heap
    for num in nums[:k]:
        heapq.heappush(min_heap, num)

    # go through the remaining numbers of the array, if the number from the
    # array is bigger than the top (smallest) number of the min-heap, remove
    # the top number from heap and add the number from array
    for num in nums[k:]:
        if num > min_heap[0]:
            heapq.heapreplace(min_heap, num)

    # the heap has the top 'K' numbers, return them in a list
    return min_heap
