"""
Given ‘M’ sorted arrays, find the smallest range that includes at least one
number from each of the ‘M’ lists.
Example 1:
Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
Output: [4, 7]
Explanation: The range [4, 7] includes 5 from L1, 4 from L2 and 7 from L3.

Example 2:
Input: L1=[1, 9], L2=[4, 12], L3=[7, 10, 16]
Output: [9, 12]
Explanation: The range [9, 12] includes 9 from L1, 12 from L2 and 10 from L3
"""

import heapq
import math


def find_smallest_range(lists: list[list[int]]) -> list[int]:
    # a min heap of (number, array index, element index); tuples compare
    # field by field, so the smallest number is on top
    min_heap: list[tuple[int, int, int]] = []
    range_start = 0
    range_end = math.inf
    current_max_number = -math.inf

    # put the 1st element of each array in the min heap
    for i, numbers in enumerate(lists):
        if numbers:
            heapq.heappush(min_heap, (numbers[0], i, 0))
            current_max_number = max(current_max_number, numbers[0])

    # take the smallest (top) element form the min heap, if it gives us
    # smaller range, update the ranges; if the array of the top element has
    # more elements, insert the next element in the heap.
    # we stop as soon as one of the arrays has run out, the heap then holds
    # fewer numbers than there are arrays
    while len(min_heap) == len(lists):
        num, array_index, element_index = heapq.heappop(min_heap)
        if range_end - range_start > current_max_number - num:
            range_start = num
            range_end = current_max_number

        element_index += 1
        if element_index < len(lists[array_index]):
            next_number = lists[array_index][element_index]
            heapq.heappush(min_heap, (next_number, array_index, element_index))
            current_max_number = max(current_max_number, next_number)

    return [range_start, int(range_end)]
