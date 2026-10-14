"""
Design a class to calculate the median of a number stream. The class should
have the following two methods:

insert_num(num): stores the number in the class
find_median(): returns the median of all numbers inserted in the class

If the count of numbers inserted in the class is even, the median will be
the average of the middle two numbers.
"""

import heapq


class Median:
    def __init__(self) -> None:
        # the smaller half of the numbers, largest on top; heapq only makes
        # min-heaps, so the numbers are stored negated
        self.max_heap: list[int] = []
        # the larger half of the numbers, smallest on top
        self.min_heap: list[int] = []

    def insert_num(self, num: int) -> None:
        if not self.max_heap or -self.max_heap[0] >= num:
            heapq.heappush(self.max_heap, -num)
        else:
            heapq.heappush(self.min_heap, num)

        # either both the heaps will have equal number of elements or
        # max-heap will have one more element than the min-heap
        if len(self.max_heap) > len(self.min_heap) + 1:
            heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        elif len(self.max_heap) < len(self.min_heap):
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))

    def find_median(self) -> float:
        if len(self.max_heap) == len(self.min_heap):
            # we have even number of elements, take the average of middle two
            # elements
            return -self.max_heap[0] / 2.0 + self.min_heap[0] / 2.0

        # because max-heap will have one more element than the min-heap
        return float(-self.max_heap[0])
