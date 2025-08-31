package twopointers

import "sort"

// Given an array of unsorted numbers, find all unique triplets in it that add up to zero.
//
// Examples
// Example 1
// Input: [-3, 0, 1, 2, -1, 1, -2]
// Output: [[-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]]
// Explanation: There are four unique triplets whose sum is equal to zero.
// Example 2
// Input: [-5, 2, -1, -2, 3]
// Output: [[-5, 2, 3], [-2, -1, 3]]
// Explanation: There are two unique triplets whose sum is equal to zero.
// Constraints:
//
// 3 <= arr.length <= 3000
// -105 <= arr[i] <= 105

func searchTriplets(arr []int) [][]int {
	sort.Ints(arr)
	triplets := make([][]int, 0)
	for i := 0; i < len(arr)-2; i++ {
		if i > 0 && arr[i] == arr[i-1] { // skip same element to avoid duplicate triplets
			continue
		}
		searchPair(arr, -arr[i], i+1, &triplets)
	}
	return triplets
}

func searchPair(arr []int, targetSum int, left int, triplets *[][]int) {
	right := len(arr) - 1
	for left < right {
		currentSum := arr[left] + arr[right]
		if currentSum == targetSum { // found the triplet
			*triplets = append(*triplets, []int{-targetSum, arr[left], arr[right]})
			left++
			right--
			for left < right && arr[left] == arr[left-1] {
				left++ // skip same element to avoid duplicate triplets
			}
			for left < right && arr[right] == arr[right+1] {
				right-- // skip same element to avoid duplicate triplets
			}
		} else if targetSum > currentSum {
			left++ // we need a pair with a bigger sum
		} else {
			right-- // we need a pair with a smaller sum
		}
	}
}
