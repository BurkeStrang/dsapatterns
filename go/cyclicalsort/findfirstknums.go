package cyclicalsort

// Given an unsorted array containing numbers and a number ‘k’,
// find the first ‘k’ missing positive numbers in the array.
//
// Example 1:
// Input: [3, -1, 4, 5, 5], k=3
// Output: [1, 2, 6]
// Explanation: The smallest missing positive numbers are 1, 2 and 6.
//
// Example 2:
// Input: [2, 3, 4], k=3
// Output: [1, 5, 6]
// Explanation: The smallest missing positive numbers are 1, 5 and 6.
//
// Example 3:
// Input: [-2, -3, 4], k=2
// Output: [1, 2]
// Explanation: The smallest missing positive numbers are 1 and 2.
// Constraints:
//
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 1000
// 1 <= k <= 1000

func findFirstK(nums []int, k int) []int {
	i := 0

	// Phase 1: Rearrange elements to their correct positions
	for i < len(nums) {
		if nums[i] > 0 && nums[i] <= len(nums) && nums[i] != nums[nums[i]-1] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i] // Swap elements to their correct positions
		} else {
			i++
		}
	}

	missingNumbers := make([]int, 0)
	extraNumbers := make(map[int]bool)

	// Phase 2: Identify missing and extra numbers
	for i = 0; i < len(nums) && len(missingNumbers) < k; i++ {
		if nums[i] != i+1 {
			missingNumbers = append(missingNumbers, i+1) // Track missing numbers
			extraNumbers[nums[i]] = true                 // Track extra numbers
		}
	}

	// Phase 3: Find remaining missing numbers
	for i = 1; len(missingNumbers) < k; i++ {
		candidateNumber := i + len(nums)
		// Ignore if the array contains the candidate number
		if !extraNumbers[candidateNumber] {
			missingNumbers = append(missingNumbers, candidateNumber) // Add remaining missing numbers
		}
	}

	return missingNumbers
}
