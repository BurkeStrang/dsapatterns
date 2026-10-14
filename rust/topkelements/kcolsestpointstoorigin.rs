use std::collections::BinaryHeap;

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

// Ord is derived so that points can go in a heap; it compares x, then y.
#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
pub struct Point {
    pub x: i32,
    pub y: i32,
}

impl Point {
    pub fn dist_from_origin(&self) -> i32 {
        // ignoring sqrt
        (self.x * self.x) + (self.y * self.y)
    }
}

pub fn find_closest_points(points: &[Point], k: usize) -> Vec<Point> {
    // a max heap of (distance from the origin, point), so the point farthest
    // from the origin is on top
    let mut max_point_heap = BinaryHeap::new();

    // put first 'k' points in the max heap
    for &point in &points[..k] {
        max_point_heap.push((point.dist_from_origin(), point));
    }

    // go through the remaining points of the input array, if a point is
    // closer to the origin than the top point of the max-heap, remove the top
    // point from heap and add the point from the input array
    for &point in &points[k..] {
        let &(farthest, _) = max_point_heap.peek().unwrap();
        if point.dist_from_origin() < farthest {
            max_point_heap.pop();
            max_point_heap.push((point.dist_from_origin(), point));
        }
    }

    // the heap has 'k' points closest to the origin, return them in a list
    max_point_heap.into_iter().map(|(_, point)| point).collect()
}
