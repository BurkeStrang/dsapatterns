package cyclicalsort

// We are given an unsorted array containing n numbers taken from the range 1 to n.
// The array has some numbers appearing twice,
// find all these duplicate numbers using constant space.
//
// Example 1:
// Input: [3, 4, 4, 5, 5]
// Output: [4, 5]
//
// Example 2:
// Input: [5, 4, 7, 2, 3, 5, 3]
// Output: [3, 5]
// Constraints:
//
// nums.length == n
// 1 <= n <=
// 1 <= nums[i] <= n
// Each element in nums appears once or twice.

func findDups(nums []int) []int {
	i := 0
	for i < len(nums) {
		if nums[i] != nums[nums[i]-1] { // Check if the current element is not in its correct position.
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i] // Swap the current element with the element at its correct position.
		} else {
			i++ // Move to the next element if the current element is already in its correct position.
		}
	}

	duplicateNumbers := make([]int, 0)
	for i = range nums {
		if nums[i] != i+1 { // Identify elements that are not in their correct positions, which are duplicates.
			duplicateNumbers = append(duplicateNumbers, nums[i]) // Add the duplicates to the list.
		}
	}
	return duplicateNumbers
}
