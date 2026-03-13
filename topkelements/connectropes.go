package topkelements

import (
	"container/heap"
)

// Given ‘N’ ropes with different lengths,
// we need to connect these ropes into one big rope with minimum cost.
// The cost of connecting two ropes is equal to the sum of their lengths.
//
// Example 1:
// Input: [1, 3, 11, 5]
// Output: 33
// Explanation: First connect 1+3(=4), then 4+5(=9), and then 9+11(=20). So the total cost is 33 (4+9+20)
//
// Example 2:
// Input: [3, 4, 5, 6]
// Output: 36
// Explanation: First connect 3+4(=7), then 5+6(=11), 7+11(=18). Total cost is 36 (7+11+18)
//
// Example 3:
// Input: [1, 3, 11, 5, 2]
// Output: 42
// Explanation: First connect 1+2(=3), then 3+3(=6), 6+5(=11), 11+11(=22). Total cost is 42 (3+6+11+22)

func minimumCostToConnectRopes(ropeLengths []int) int {
	minHeap := &MinHeap{}
	heap.Init(minHeap)

	// Add all ropes to the min heap
	for _, length := range ropeLengths {
		heap.Push(minHeap, length)
	}
	// so in the min heap the lengths for example 1 could be [1 3 11 5]
	// only the top of the heap is guaranteed to be the lowest length, the rest
	// of the values are not sorted
	result := 0
	// Go through the values of the heap, connect the top (lowest) rope lengths
	// from the min heap, and push the result back to the min heap.
	// Keep doing this until the heap is left with only one rope.
	for minHeap.Len() > 1 {
		temp := heap.Pop(minHeap).(int) + heap.Pop(minHeap).(int)
		// [1, 3, 5, 11]
		// [4, 5, 11]
		// [9, 11]
		// [20]
		result += temp
		// 4 + 9 + 20 = 33
		heap.Push(minHeap, temp)
	}

	return result
}
