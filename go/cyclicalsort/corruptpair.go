package cyclicalsort

// We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’.
// The array originally contained all the numbers from 1 to ‘n’,
// but due to a data error,
// one of the numbers got duplicated which also resulted in one number going missing.
// Find both these numbers.
//
// Example 1:
// Input: [3, 1, 2, 5, 2]
// Output: [2, 4]
// Explanation: '2' is duplicated and '4' is missing.
//
// Example 2:
// Input: [3, 1, 2, 3, 6, 4]
// Output: [3, 5]
// Explanation: '3' is duplicated and '5' is missing.
// Constraints:
//
// 2 <= nums.length <=
// 1 <= nums[i] <=

func findCorrupt(nums []int) []int {
	i := 0
	for i < len(nums) {
		// If the current number is not in its correct position, swap it with the number at its correct position.
		if nums[i] != nums[nums[i]-1] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		} else {
			i++
		}
	}
	// Iterate through the slice to find the first misplaced number.
	for i = range nums {
		if nums[i] != i+1 {
			return []int{nums[i], i + 1}
		}
	}
	// If no numbers are swapped, return [-1, -1].
	return []int{-1, -1}
}
