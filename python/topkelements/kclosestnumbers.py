"""
Given a sorted number array and two integers ‘K’ and ‘X’,
find ‘K’ closest numbers to ‘X’ in the array.
Return the numbers in the sorted order.
‘X’ is not necessarily present in the array.

Example 1:
Input: [5, 6, 7, 8, 9], K = 3, X = 7
Output: [6, 7, 8]

Example 2:
Input: [2, 4, 5, 6, 9], K = 3, X = 6
Output: [4, 5, 6]

Example 3:
Input: [2, 4, 5, 6, 9], K = 3, X = 10
Output: [5, 6, 9]
"""

import heapq


def binary_search(arr: list[int], target: int) -> int:
    """Returns the index of the target, or of the number closest to it from
    below when the target is not in the array."""
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == target:
            return mid
        if arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    if low > 0:
        return low - 1
    return low


def find_closest_elements(arr: list[int], k: int, x: int) -> list[int]:
    index = binary_search(arr, x)
    # 'low' should not be less than zero
    low = max(index - k, 0)
    # 'high' should not be greater the size of the array
    high = min(index + k, len(arr) - 1)

    # a min heap of (absolute difference from 'x', index)
    min_heap: list[tuple[int, int]] = []
    # add all candidate elements to the min heap, sorted by their absolute
    # difference from 'x'
    for i in range(low, high + 1):
        heapq.heappush(min_heap, (abs(arr[i] - x), i))

    # we need the top 'k' elements having the smallest difference from 'x'
    result: list[int] = []
    for _ in range(k):
        if not min_heap:
            break
        _, i = heapq.heappop(min_heap)
        result.append(arr[i])

    result.sort()
    return result
