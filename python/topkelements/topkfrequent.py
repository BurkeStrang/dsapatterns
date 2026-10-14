"""
Given an unsorted array of numbers,
find the top ‘K’ frequently occurring numbers in it.

Example 1:
Input: [1, 3, 5, 12, 11, 12, 11], K = 2
Output: [12, 11]
Explanation: Both '11' and '12' appeared twice.

Example 2:
Input: [5, 12, 11, 3, 11], K = 2
Output: [11, 5] or [11, 12] or [11, 3]
Explanation: Only '11' appeared twice; all other numbers appeared once.
"""

import heapq
from collections import Counter


def find_top_k_frequent_numbers(nums: list[int], k: int) -> list[int]:
    # Find the frequency of each number
    num_frequency_map = Counter(nums)

    # Create a min heap to store (frequency, number) entries
    min_freq_heap: list[tuple[int, int]] = []

    # Go through all numbers in num_frequency_map and push them into the
    # min heap. If the heap size is more than k, remove the smallest (top)
    # entry
    for num, frequency in num_frequency_map.items():
        heapq.heappush(min_freq_heap, (frequency, num))
        if len(min_freq_heap) > k:
            heapq.heappop(min_freq_heap)

    # Create a list of top k frequent numbers; the heap gives the least
    # frequent first, so fill the list from the back
    top_numbers = [0] * len(min_freq_heap)
    for i in range(len(top_numbers) - 1, -1, -1):
        top_numbers[i] = heapq.heappop(min_freq_heap)[1]
    return top_numbers
