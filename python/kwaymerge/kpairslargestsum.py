"""
Given two sorted arrays in descending order,
find ‘K’ pairs with the largest sum where each pair consists of numbers from
both the arrays.

Example 1:
Input: nums1=[9, 8, 2], nums2=[6, 3, 1], K=3
Output: [9, 3], [9, 6], [8, 6]
Explanation: These 3 pairs have the largest sum. No other pair has a sum
larger than any of these.

Example 2:
Input: nums1=[5, 2, 1], nums2=[2, -1], K=3
Output: [5, 2], [5, -1], [2, 2]
"""

import heapq


def find_k_largest_pairs(
    nums1: list[int], nums2: list[int], k: int
) -> list[list[int]]:
    """Finds the k pairs with the largest sums."""
    # a min heap of (sum of the pair, first number, second number), so the
    # pair with the smallest sum is on top
    min_heap: list[tuple[int, int, int]] = []
    for i in range(min(k, len(nums1))):
        for j in range(min(k, len(nums2))):
            pair_sum = nums1[i] + nums2[j]
            if len(min_heap) < k:
                heapq.heappush(min_heap, (pair_sum, nums1[i], nums2[j]))
                continue

            # if the sum of the two numbers from the two arrays is smaller
            # than the smallest (top) element of the heap, we can 'break'
            # here.
            if pair_sum < min_heap[0][0]:
                break

            # we've a pair with a larger sum, remove top and insert this pair
            # in heap
            heapq.heapreplace(min_heap, (pair_sum, nums1[i], nums2[j]))

    result: list[list[int]] = []
    while min_heap:
        _, first, second = heapq.heappop(min_heap)
        result.append([first, second])
    return result
