// Package cyclicalsort organizes sorting problems
package cyclicalsort

// We are given an array containing n objects.
// Each object, when created,
// was assigned a unique number from the range 1 to n based on their creation sequence.
// This means that the object with sequence number 3 was created just
// before the object with sequence number 4.
// Write a function to sort the objects in-place on their creation sequence
// number in  without using any extra space.
// For simplicity, let's assume we are passed an integer array containing only the sequence numbers,
// though each number is actually an object.
//
// Example 1:
// Input: [3, 1, 5, 4, 2]
// Output: [1, 2, 3, 4, 5]
//
// Example 2:
// Input: [2, 6, 4, 3, 1, 5]
// Output: [1, 2, 3, 4, 5, 6]
//
// Example 3:
// Input: [1, 5, 6, 4, 3, 2]
// Output: [1, 2, 3, 4, 5, 6]
// Constraints:
//
// n == nums.length
// 1 <= n <=
// 0 <= nums[i] <= n

func sort(nums []int) []int {
	i := 0
	for i < len(nums) {
		j := nums[i] - 1        // Calculate the index where the current element should be placed.
		if nums[i] != nums[j] { // Check if the current element is not in its correct position.
			swap(nums, i, j) // Swap the current element with the one at its correct position.
		} else {
			i++
		}
	}
	return nums
}

// swap swaps two elements in the slice at positions i and j.
func swap(arr []int, i, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}
