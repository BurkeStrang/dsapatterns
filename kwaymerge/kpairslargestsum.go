package kwaymerge

// Given two sorted arrays in descending order,
// find ‘K’ pairs with the largest sum where each pair consists of numbers from both the arrays.
//
// Example 1:
// Input: nums1=[9, 8, 2], nums2=[6, 3, 1], K=3
// Output: [9, 3], [9, 6], [8, 6]
// Explanation: These 3 pairs have the largest sum. No other pair has a sum larger than any of these.
//
// Example 2:
// Input: nums1=[5, 2, 1], nums2=[2, -1], K=3
// Output: [5, 2], [5, -1], [2, 2]

import (
	"container/heap"
)

// IntHeap is a min-heap of int slices.
type IntHeap [][]int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i][0]+h[i][1] < h[j][0]+h[j][1] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x any) {
	*h = append(*h, x.([]int))
}

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// findKLargestPairs finds k largest pairs.
func findKLargestPairs(nums1 []int, nums2 []int, k int) [][]int {
	minHeap := &IntHeap{}
	heap.Init(minHeap)
	for i := 0; i < len(nums1) && i < k; i++ {
		for j := 0; j < len(nums2) && j < k; j++ {
			if minHeap.Len() < k {
				heap.Push(minHeap, []int{nums1[i], nums2[j]})
			} else {
				// if the sum of the two numbers from the two arrays is smaller than the
				// smallest (top) element of the heap, we can 'break' here.
				if nums1[i]+nums2[j] < (*minHeap)[0][0]+(*minHeap)[0][1] {
					break
				} else {
					// we've a pair with a larger sum, remove top and insert this pair in heap
					heap.Pop(minHeap)
					heap.Push(minHeap, []int{nums1[i], nums2[j]})
				}
			}
		}
	}

	result := make([][]int, 0, minHeap.Len())
	for minHeap.Len() > 0 {
		result = append(result, heap.Pop(minHeap).([]int))
	}
	return result
}
