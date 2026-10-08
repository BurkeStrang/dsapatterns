package cyclicalsort

// We are given an unsorted array containing numbers taken from the range 1 to ‘n’.
// The array can have duplicates, which means some numbers will be missing.
// Find all those missing numbers.
//
// Example 1:
// Input: [2, 3, 1, 8, 2, 3, 5, 1]
// Output: 4, 6, 7
// Explanation: The array should have all numbers from 1 to 8,
// due to duplicates 4, 6, and 7 are missing.
//
// Example 2:
// Input: [2, 4, 1, 2]
// Output: 3
//
// Example 3:
// Input: [2, 3, 2, 1]
// Output: 4
// Constraints:
//
// n == nums.length
// 1 <= n <=
// 1 <= nums[i] <= n

func findNumbers(nums []int) []int {
	i := 0 // Initialize a pointer for iterating through the slice.
	for i < len(nums) {
		if nums[i] != nums[nums[i]-1] {
			// Swap the current element with the element at its correct position.
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		} else {
			i++
		}
	}

	var missingNumbers []int

	for i = range nums {
		if nums[i] != i+1 {
			// If the element at index 'i' is not in the correct position, add it to the missing numbers list.
			missingNumbers = append(missingNumbers, i+1)
		}
	}
	return missingNumbers
}
