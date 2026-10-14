"""
Given an array of intervals, find the next interval of each interval. In a
list of intervals, for an interval 'i' its next interval 'j' will have the
smallest 'start' greater than or equal to the 'end' of 'i'.

Write a function to return an array containing indices of the next interval
of each input interval. If there is no next interval of a given interval,
return -1. It is given that none of the intervals have the same start
point.
"""

import heapq
from dataclasses import dataclass


@dataclass
class Interval:
    start: int
    end: int


def find_next_interval(intervals: list[Interval]) -> list[int]:
    n = len(intervals)
    # max-heaps of (start, index) and (end, index); heapq only makes
    # min-heaps, so both numbers are stored negated
    max_start_heap: list[tuple[int, int]] = []
    max_end_heap: list[tuple[int, int]] = []
    result = [-1] * n  # Default to -1

    # Initialize heaps
    for i, interval in enumerate(intervals):
        heapq.heappush(max_start_heap, (-interval.start, -i))
        heapq.heappush(max_end_heap, (-interval.end, -i))

    # Go through the intervals from the highest end to the lowest and find
    # the next interval of each
    while max_end_heap:
        top_end, end_index = heapq.heappop(max_end_heap)
        top_end, end_index = -top_end, -end_index

        # find the interval that has the closest 'start'; the last one popped
        # here is the one with the smallest start that is still >= the end
        top_start = None
        while max_start_heap and -max_start_heap[0][0] >= top_end:
            top_start = heapq.heappop(max_start_heap)

        if top_start is not None:
            result[end_index] = -top_start[1]
            # put the interval back as it could be the next interval of other
            # intervals
            heapq.heappush(max_start_heap, top_start)

    return result
