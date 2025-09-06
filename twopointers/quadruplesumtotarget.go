package twopointers

import "sort"

// Given an array of unsorted numbers and a target number,
// find all unique quadruplets in it, whose sum is equal to the target number.
//
// Example 1:
//
// Input: [4, 1, 2, -1, 1, -3], target=1
// Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
// Explanation: Both the quadruplets add up to the target.
// Example 2:
//
// Input: [2, 0, -1, 1, -2, 2], target=2
// Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
// Explanation: Both the quadruplets add up to the target.
// Constraints:
//
// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

func searchQuadruplets(arr []int, target int) [][]int {
	sort.Ints(arr)
	var quadruplets [][]int
	for i := 0; i < len(arr)-3; i++ {
		// skip same element to avoid duplicate quadruplets
		if i > 0 && arr[i] == arr[i-1] {
			continue
		}
		for j := i + 1; j < len(arr)-2; j++ {
			// skip same element to avoid duplicate quadruplets
			if j > i+1 && arr[j] == arr[j-1] {
				continue
			}
			quadruplets = searchPairs(arr, target, i, j, quadruplets)
		}
	}
	return quadruplets
}

func searchPairs(arr []int, targetSum, first, second int, quadruplets [][]int) [][]int {
	left := second + 1
	right := len(arr) - 1
	for left < right {
		sum := arr[first] + arr[second] + arr[left] + arr[right]
		if sum == targetSum { // found the quadruplet
			quadruplets = append(quadruplets, []int{arr[first], arr[second], arr[left], arr[right]})
			left++
			right--
			for left < right && arr[left] == arr[left-1] {
				left++ // skip same element to avoid duplicate quadruplets
			}
			for left < right && arr[right] == arr[right+1] {
				right-- // skip same element to avoid duplicate quadruplets
			}
		} else if sum < targetSum {
			left++ // we need a pair with a bigger sum
		} else {
			right-- // we need a pair with a smaller sum
		}
	}
	return quadruplets
}
