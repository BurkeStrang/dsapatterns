"""
Given an array of points in a 2D plane, find ‘K’ closest points to the
origin.

Example 1:
Input: points = [[1,2],[1,3]], K = 1
Output: [[1,2]]
Explanation: The Euclidean distance between (1, 2) and the origin is sqrt(5).
The Euclidean distance between (1, 3) and the origin is sqrt(10).
Since sqrt(5) < sqrt(10), therefore (1, 2) is closer to the origin.

Example 2:
Input: point = [[1, 3], [3, 4], [2, -1]], K = 2
Output: [[1, 3], [2, -1]]
"""

import heapq
from dataclasses import dataclass


# order=True lets points be compared by x, then y, so that they can be
# sorted
@dataclass(frozen=True, order=True)
class Point:
    x: int
    y: int

    def dist_from_origin(self) -> int:
        # ignoring sqrt
        return (self.x * self.x) + (self.y * self.y)


def find_closest_points(points: list[Point], k: int) -> list[Point]:
    # a max heap of (distance from the origin, point), so the point farthest
    # from the origin is on top; heapq only makes min-heaps, so the distance
    # is stored negated
    max_point_heap: list[tuple[int, Point]] = []

    # put first 'k' points in the max heap
    for point in points[:k]:
        heapq.heappush(max_point_heap, (-point.dist_from_origin(), point))

    # go through the remaining points of the input array, if a point is
    # closer to the origin than the top point of the max-heap, remove the top
    # point from heap and add the point from the input array
    for point in points[k:]:
        if point.dist_from_origin() < -max_point_heap[0][0]:
            heapq.heapreplace(
                max_point_heap, (-point.dist_from_origin(), point)
            )

    # the heap has 'k' points closest to the origin, return them in a list
    return [point for _, point in max_point_heap]
