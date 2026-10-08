package topkelements

import "container/heap"

// Given an unsorted array of numbers, find the ‘K’ largest numbers in it.
//
// Example 1:
// Input: [3, 1, 5, 12, 2, 11], K = 3
// Output: [5, 12, 11]
//
// Example 2:
// Input: [5, 12, 11, -1, 12], K = 3
// Output: [12, 11, 12]

// findKLargestNumbers - keeps all comments same and method name same
func findKLargestNumbers(nums []int, k int) []int {
	minHeap := &MinHeap{}
	heap.Init(minHeap)
	// put first 'K' numbers in the min heap
	for i := range k {
		heap.Push(minHeap, nums[i])
	}

	// go through the remaining numbers of the array, if the number from the array is
	// bigger than the top (smallest) number of the min-heap, remove the top number from
	// heap and add the number from array
	for i := k; i < len(nums); i++ {
		if nums[i] > (*minHeap)[0] {
			heap.Pop(minHeap)
			heap.Push(minHeap, nums[i])
		}
	}

	// the heap has the top 'K' numbers, return them in a list
	result := make([]int, minHeap.Len())
	for i := range result {
		result[i] = heap.Pop(minHeap).(int)
	}
	return result
}
