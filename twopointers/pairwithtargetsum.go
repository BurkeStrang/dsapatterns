// Given an array of numbers sorted in ascending order and a target sum,
// find a pair in the array whose sum is equal to the given target.
//
// Write a function to return the indices of the two numbers (i.e. the pair)
// such that they add up to the given target. If no such pair exists return [-1, -1].
//
// Example 1:
//
// Input: [1, 2, 3, 4, 6], target=6
// Output: [1, 3]
// Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
// Example 2:
//
// Input: [2, 5, 9, 11], target=11
// Output: [0, 2]
// Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11

package twopointers

func search(arr []int, targetsum int) []int {
	left, right := 0, len(arr)-1
	for left < right {
		sum := arr[left] + arr[right]
		if sum == targetsum {
			return []int{left, right}
		} else if sum < targetsum {
			left++
		} else {
			right--
		}
	}
	return []int{-1, -1}
}
