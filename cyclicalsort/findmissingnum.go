package cyclicalsort

// We are given an array containing n distinct numbers taken from the range 0 to n.
// Since the array has only n numbers out of the total n+1 numbers, find the missing number.
//
// Example 1:
// Input: [4, 0, 3, 1]
// Output: 2
//
// Example 2:
// Input: [8, 3, 5, 2, 4, 6, 0, 1]
// Output: 7
//
// Constraints:
// n == nums.length
// 1 <= n <=
// 0 <= nums[i] <= n
// All the numbers of nums are unique.

func findMissingNumber(nums []int) int {
	i := 0
	for i < len(nums) {
		if nums[i] < len(nums) && nums[i] != nums[nums[i]] {
			nums[i], nums[nums[i]] = nums[nums[i]], nums[i]
		} else {
			i++
		}
	}

	// Find the first number missing from its index, that will be our required number
	for i = range nums {
		if nums[i] != i {
			return i
		}
	}

	return len(nums)
}
