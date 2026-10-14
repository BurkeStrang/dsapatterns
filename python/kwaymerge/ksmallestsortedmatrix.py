"""
Given an N * N matrix where each row and column is sorted in ascending order,
find the Kth smallest element in the matrix.
Example 1:
Input: Matrix=[
    [2, 6, 8],
    [3, 7, 10],
    [5, 8, 11]
  ],
  K=5
Output: 7
Explanation: The 5th smallest number in the matrix is 7.
"""

import heapq


def find_kth_smallest_point(matrix: list[list[int]], k: int) -> int:
    """Finds the Kth smallest element in a matrix."""
    # a min heap of (number, row, column); tuples compare field by field, so
    # the smallest number is on top
    min_heap: list[tuple[int, int, int]] = []

    # put the 1st element of each row in the min heap
    # we don't need to push more than 'k' elements in the heap
    for row in range(min(k, len(matrix))):
        heapq.heappush(min_heap, (matrix[row][0], row, 0))

    # take the smallest (top) element form the min heap, if the running count
    # is equal to k return the number. if the row of the top element has more
    # elements, add the next element to the heap
    number_count = 0
    result = 0
    while min_heap:
        num, row, col = heapq.heappop(min_heap)
        result = num
        number_count += 1
        if number_count == k:
            break
        col += 1
        if col < len(matrix[row]):
            heapq.heappush(min_heap, (matrix[row][col], row, col))
    return result
