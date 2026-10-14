// Given an array of points in a 2D plane, find ‘K’ closest points to the
// origin.
//
// Example 1:
// Input: points = [[1,2],[1,3]], K = 1
// Output: [[1,2]]
// Explanation: The Euclidean distance between (1, 2) and the origin is sqrt(5).
// The Euclidean distance between (1, 3) and the origin is sqrt(10).
// Since sqrt(5) < sqrt(10), therefore (1, 2) is closer to the origin.
//
// Example 2:
// Input: point = [[1, 3], [3, 4], [2, -1]], K = 2
// Output: [[1, 3], [2, -1]]

import { Heap } from "../common/heap.ts";

export interface Point {
  x: number;
  y: number;
}

export function distFromOrigin(point: Point): number {
  // ignoring sqrt
  return point.x * point.x + point.y * point.y;
}

export function findClosestPoints(points: Point[], k: number): Point[] {
  // a max heap of the points, so the point farthest from the origin is on
  // top
  const maxPointHeap = new Heap<Point>(
    (a, b) => distFromOrigin(a) > distFromOrigin(b),
  );

  // put first 'k' points in the max heap
  for (const point of points.slice(0, k)) {
    maxPointHeap.push(point);
  }

  // go through the remaining points of the input array, if a point is
  // closer to the origin than the top point of the max-heap, remove the top
  // point from heap and add the point from the input array
  for (const point of points.slice(k)) {
    const farthest = maxPointHeap.peek();
    if (
      farthest !== undefined &&
      distFromOrigin(point) < distFromOrigin(farthest)
    ) {
      maxPointHeap.pop();
      maxPointHeap.push(point);
    }
  }

  // the heap has 'k' points closest to the origin, return them in a list
  return maxPointHeap.toArray();
}
