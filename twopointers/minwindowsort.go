package twopointers

import "math"

// Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.
//
// Example 1:
//
// Input: [1, 2, 5, 3, 7, 10, 9, 12]
// Output: 5
// Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted
// Example 2:
//
// Input: [1, 3, 2, 0, -1, 7, 10]
// Output: 5
// Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted
// Example 3:
//
// Input: [1, 2, 3]
// Output: 0
// Explanation: The array is already sorted
// Example 4:
//
// Input: [3, 2, 1]
// Output: 3
// Explanation: The whole array needs to be sorted.
// Constraints:
//
// 1 <= arr.length <= 104
// -105 <= arr[i] <= 105


func minSort(arr []int) int {
	low := 0
	high := len(arr) - 1

	// find the first number out of sorting order from the beginning
	for low < len(arr)-1 && arr[low] <= arr[low+1] {
		low++
	}

	if low == len(arr)-1 { // if the array is sorted
		return 0
	}

	// find the first number out of sorting order from the end
	for high > 0 && arr[high] >= arr[high-1] {
		high--
	}

	// find the maximum and minimum of the subarray
	subarrayMax := math.MinInt32
	subarrayMin := math.MaxInt32
	for k := low; k <= high; k++ {
		if arr[k] > subarrayMax {
			subarrayMax = arr[k]
		}
		if arr[k] < subarrayMin {
			subarrayMin = arr[k]
		}
	}

	// extend the subarray to include any number which is bigger than the minimum of
	// the subarray
	for low > 0 && arr[low-1] > subarrayMin {
		low--
	}
	// extend the subarray to include any number which is smaller than the maximum of
	// the subarray
	for high < len(arr)-1 && arr[high+1] < subarrayMax {
		high++
	}

	return high - low + 1
}
