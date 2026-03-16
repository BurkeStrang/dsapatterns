package topkelements

import (
	"container/heap"
	"math"
	"sort"
)

// Given a sorted number array and two integers ‘K’ and ‘X’,
// find ‘K’ closest numbers to ‘X’ in the array.
// Return the numbers in the sorted order.
// ‘X’ is not necessarily present in the array.
//
// Example 1:
// Input: [5, 6, 7, 8, 9], K = 3, X = 7
// Output: [6, 7, 8]
//
// Example 2:
// Input: [2, 4, 5, 6, 9], K = 3, X = 6
// Output: [4, 5, 6]
//
// Example 3:
// Input: [2, 4, 5, 6, 9], K = 3, X = 10
// Output: [5, 6, 9]

func findClosestElements(arr []int, k int, x int) []int {
	index := binarySearch(arr, x)
	low := index - k
	high := index + k
	low = max(low, 0)            // 'low' should not be less than zero
	high = min(high, len(arr)-1) // 'high' should not be greater the size of the array

	minHeap := &MinClosestHeap{}
	heap.Init(minHeap)

	// add all candidate elements to the min heap, sorted by their absolute difference from 'X'
	for i := low; i <= high; i++ {
		heap.Push(minHeap, &ClosestEntry{key: int(math.Abs(float64(arr[i] - x))), value: i})
	}

	// we need the top 'K' elements having the smallest difference from 'X'
	result := []int{}
	for range k {
		entry := heap.Pop(minHeap).(*ClosestEntry)
		result = append(result, arr[entry.value])
	}

	sort.Ints(result)
	return result
}

func binarySearch(arr []int, target int) int {
	low := 0
	high := len(arr) - 1
	for low <= high {
		mid := low + (high-low)/2
		if arr[mid] == target {
			return mid
		}
		if arr[mid] < target {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	if low > 0 {
		return low - 1
	}
	return low
}
