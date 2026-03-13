// package topkelements
package topkelements

import "container/heap"

// Given an unsorted array of numbers, find Kth smallest number in it.
// Please note that it is the Kth smallest number in the sorted order,
// not the Kth distinct element.
// Note: For a detailed discussion about different approaches to solve this problem,
// take a look at Kth Smallest Number.
//
// Example 1:
// Input: [1, 5, 12, 2, 11, 5], K = 3
// Output: 5
// Explanation: The 3rd smallest number is '5', as the first two smaller numbers are [1, 2].
//
// Example 2:
// Input: [1, 5, 12, 2, 11, 5], K = 4
// Output: 5
// Explanation: The 4th smallest number is '5', as the first three small numbers are [1, 2, 5].
//
// Example 3:
// Input: [5, 12, 11, -1, 12], K = 3
// Output: 11
// Explanation: The 3rd smallest number is '11', as the first two small numbers are [5, -1].

func findKthSmallestNumber(nums []int, k int) int {
	maxHeap := &MaxHeap{}
	heap.Init(maxHeap)

	// Put first k numbers in the max heap
	for i := range k {
		heap.Push(maxHeap, nums[i])
	}

	// Go through the remaining numbers of the array, if the number from the array is
	// smaller than the top (biggest) number of the heap, remove the top number from
	// heap and add the number from array
	for i := k; i < len(nums); i++ {
		if nums[i] < (*maxHeap)[0] {
			heap.Pop(maxHeap)
			heap.Push(maxHeap, nums[i])
		}
	}

	// The root of the heap has the Kth smallest number
	return (*maxHeap)[0]
}

type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
