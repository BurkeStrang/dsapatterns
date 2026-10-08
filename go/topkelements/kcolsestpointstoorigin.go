package topkelements

import "container/heap"

// Given an array of points in a 2D plane, find ‘K’ closest points to the origin.
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

func findClosestPoints(points []*Point, k int) []*Point {
	maxPointHeap := MaxPointHeap{}
	heap.Init(&maxPointHeap)

	// put first 'k' points in the max heap
	for i := range k {
		heap.Push(&maxPointHeap, points[i])
	}

	// go through the remaining points of the input array, if a point is closer to the
	// origin than the top point of the max-heap, remove the top point from heap and add
	// the point from the input array
	for i := k; i < len(points); i++ {
		if points[i].DistFromOrigin() < maxPointHeap[0].DistFromOrigin() {
			heap.Pop(&maxPointHeap)
			heap.Push(&maxPointHeap, points[i])
		}
	}

	// the heap has 'k' points closest to the origin, return them in a slice
	result := make([]*Point, k)
	for i := range k {
		result[i] = heap.Pop(&maxPointHeap).(*Point)
	}
	return result
}
