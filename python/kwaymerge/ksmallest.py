"""
Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.

Example 1:
Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
Output: 4
Explanation: The 5th smallest number among all the arrays is 4, this can be
verified from
the merged list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]

Example 2:
Input: L1=[5, 8, 9], L2=[1, 7], K=3
Output: 7
Explanation: The 3rd smallest number among all the arrays is 7.
"""

import heapq


def find_kth_smallest(lists: list[list[int]], k: int) -> int:
    # a min heap of (number, array index, element index); tuples compare
    # field by field, so the smallest number is on top
    min_heap: list[tuple[int, int, int]] = []

    # put the 1st element of each array in the min heap
    for i, numbers in enumerate(lists):
        if numbers:
            heapq.heappush(min_heap, (numbers[0], i, 0))

    # take the smallest (top) element form the min heap, if the running count
    # is equal to k return the number if the array of the top element has
    # more elements, add the next element to the heap
    number_count = 0
    result = 0
    while min_heap:
        num, array_index, element_index = heapq.heappop(min_heap)
        result = num
        number_count += 1
        if number_count == k:
            break
        element_index += 1
        if element_index < len(lists[array_index]):
            heapq.heappush(
                min_heap,
                (lists[array_index][element_index], array_index, element_index),
            )
    return result
