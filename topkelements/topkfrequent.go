package topkelements

import "container/heap"

// Given an unsorted array of numbers,
// find the top ‘K’ frequently occurring numbers in it.
//
// Example 1:
// Input: [1, 3, 5, 12, 11, 12, 11], K = 2
// Output: [12, 11]
// Explanation: Both '11' and '12' appeared twice.
//
// Example 2:
// Input: [5, 12, 11, 3, 11], K = 2
// Output: [11, 5] or [11, 12] or [11, 3]
// Explanation: Only '11' appeared twice; all other numbers appeared once.

func findTopKFrequentNumbers(nums []int, k int) []int {
	// Find the frequency of each number
	numFrequencyMap := make(map[int]int)
	for _, n := range nums {
		numFrequencyMap[n]++
	}

	// Create a min heap to store entries with frequency
	minFreqHeap := &MinFreqHeap{}
	heap.Init(minFreqHeap)

	// Go through all numbers in numFrequencyMap and push them into the minHeap
	// If the heap size is more than k, remove the smallest (top) entry
	for num, frequency := range numFrequencyMap {
		entry := Entry{num, frequency}
		heap.Push(minFreqHeap, entry)
		if minFreqHeap.Len() > k {
			heap.Pop(minFreqHeap)
		}
	}

	// Create a list of top k frequent numbers
	topNumbers := make([]int, k)
	for i := k - 1; i >= 0; i-- {
		entry := heap.Pop(minFreqHeap).(Entry)
		topNumbers[i] = entry.Num
	}

	return topNumbers
}

