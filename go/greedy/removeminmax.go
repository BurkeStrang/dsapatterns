package greedy

// Determine the minimum number of deletions required to remove
// the smallest and the largest elements from an array of integers.
// In each deletion,
// you are allowed to remove either the first (leftmost) or the last (rightmost) element of the array.
//
// Example 1:
// Input: [3, 2, 5, 1, 4]
// Expected Output: 3
// Justification: The smallest element is 1 and the largest is 5. Removing 4, 1, and then 5
// (or 5, 4, and then 1) in three moves is the most efficient strategy.
//
// Example 2:
// Input: [7, 5, 6, 8, 1]
// Expected Output: 2
// Justification: Here, 1 is the smallest, and 8 is the largest. Removing 1 and then 8 in two moves is the optimal strategy.
//
// Example 3:
// Input: [2, 4, 10, 1, 3, 5]
// Expected Output: 4
// Justification: The smallest is 1 and the largest is 10. One strategy is to remove 2, 4, 10, and then 1 in four moves.
//
// Constraints:
// 1 <= nums.length <= 105
// -105 <= nums[i] <= 105
// The integers in nums are distinct.

func minMoves(nums []int) int {
	n := len(nums)
	minIndex, maxIndex := 0, 0
	minVal, maxVal := nums[0], nums[0]

	// Find the indexes of the minimum and maximum elements
	for i, val := range nums {
		if val < minVal {
			minIndex, minVal = i, val
		}
		if val > maxVal {
			maxIndex, maxVal = i, val
		}
	}

	// Calculate distances from both ends
	minDistStart := minIndex + 1
	minDistEnd := n - minIndex
	maxDistStart := maxIndex + 1
	maxDistEnd := n - maxIndex

	// Determine the most efficient sequence of moves
	totalMoves := min(
		max(minDistStart, maxDistStart),
		min(min(minDistStart+maxDistEnd, minDistEnd+maxDistStart), max(minDistEnd, maxDistEnd)))

	return totalMoves
}
