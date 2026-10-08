package slidingwindow

// Given an array nums with positive numbers and a positive integer target,
// return the count of contiguous subarrays whose product is less than the target number.
//
// Examples
// Example 1:
// Input: nums = [2, 5, 3, 10], target=30
// Output: 6
// Explanation: There are six contiguous subarrays ([2], [5], [2, 5], [3], [5, 3], [10]) whose product is less than the target.
//
// Example 2:
// Input: nums = [8, 2, 6, 5], target=50
// Output: 7
// Explanation: There are seven contiguous subarrays ([8], [2], [8, 2], [6], [2, 6], [5], [6, 5]) whose product is less than the target.
//
// Example 3:
// Input: nums = [10, 5, 2, 6], k = 0
// Expected Output: 0
// Explanation: Subarrays with product less than 0 doesn't exists.
//
// Constraints:
// 1 <= nums.length <= 3 * 104
// 1 <= nums[i] <= 1000
// 0 <= k <= 106

func findSubarrayCount(nums []int, target int) int {
	// Handle edge cases where k is 0 or 1 (no subarrays possible)
	if target <= 1 {
		return 0
	}
	totalCount := 0
	// Variable to store the product of elements in the current subarray.
	product := 1
	// Left boundary of the current subarray.
	left := 0
	// Iterate over the array using 'right' as the right boundary of the current
	// subarray.
	for right := range nums {
		// Update the product with the current element.
		product *= nums[right]

		// If the product is greater than or equal to the target, slide the left
		// boundary to the right until product is less than target.
		for product >= target && left < len(nums) {
			product /= nums[left]
			left++
		}
		// Update the total count by adding the number of valid subarrays with the current window size
		totalCount += right - left + 1 // right - left + 1 represents the current window size
	}
	// Return the result.
	return totalCount
}
