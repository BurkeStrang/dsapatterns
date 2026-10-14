"""
Given an array of numbers and a number 'k', find the median of all the 'k'
sized sub-arrays (or windows) of the array.

Example 1:
Input: nums=[1, 2, -1, 3, 5], k = 2
Output: [1.5, 0.5, 1.0, 4.0]

Example 2:
Input: nums=[1, 2, -1, 3, 5], k = 3
Output: [1.0, 2.0, 3.0]
"""

import heapq


class Window:
    def __init__(self) -> None:
        # the smaller half of the window, largest on top; heapq only makes
        # min-heaps, so the numbers are stored negated
        self.max_heap: list[int] = []
        # the larger half of the window, smallest on top
        self.min_heap: list[int] = []

    def rebalance_heaps(self) -> None:
        # either both the heaps will have equal number of elements or
        # max-heap will have one more element than the min-heap
        if len(self.max_heap) > len(self.min_heap) + 1:
            heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        elif len(self.max_heap) < len(self.min_heap):
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))


def remove(heap: list[int], value: int) -> None:
    """Takes one copy of value out of the heap. heapq can only pop the top, so
    this removes it from the list and turns the list back into a heap."""
    heap.remove(value)
    heapq.heapify(heap)


def find_sliding_window_median(nums: list[int], k: int) -> list[float]:
    result: list[float] = []
    window = Window()
    for i, num in enumerate(nums):
        if not window.max_heap or -window.max_heap[0] >= num:
            heapq.heappush(window.max_heap, -num)
        else:
            heapq.heappush(window.min_heap, num)
        window.rebalance_heaps()

        # if we have at least 'k' elements in the sliding window
        if i - k + 1 >= 0:
            # add the median to the result
            max_top = -window.max_heap[0]
            if len(window.max_heap) == len(window.min_heap):
                # we have even number of elements, take the average of middle
                # two elements
                result.append((max_top + window.min_heap[0]) / 2.0)
            else:
                # because max-heap will have one more element than the
                # min-heap
                result.append(float(max_top))

            # remove the element going out of the sliding window
            element_to_be_removed = nums[i - k + 1]
            if element_to_be_removed <= max_top:
                remove(window.max_heap, -element_to_be_removed)
            else:
                remove(window.min_heap, element_to_be_removed)
            window.rebalance_heaps()

    return result
