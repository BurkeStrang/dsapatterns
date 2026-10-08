package levelordertraversal

import "math"

// Given the root of a binary tree, return an array containing the largest value in each row of the tree (0-indexed).
//
// Examples
// Example 1
// Input: root = [1, 2, 3, 4, 5, null, 6]
// Expected Output: [1, 3, 6]
// Image
// Justification:
// The first row contains 1. The largest value is 1.
// The second row has 2 and 3, and the largest is 3.
// The third row has 4, 5, and 6, and the largest is 6.
// Example 2
// Input: root = [7, 4, 8, 2, 5, null, 9, null, 3]
// Expected Output: [7, 8, 9, 3]
// Image
// Justification:
// The first row contains 7, and the largest value is 7.
// The second row has 4 and 8, and the largest is 8.
// The third row has 2, 5, and 9, and the largest is 9.
// The fourth row has 3, and the largest is 3.
// Example 3
// Input: root = [10, 5]
// Expected Output: [10, 5]
// Justification:
// The first row has 10, and the largest value is 10.
// The second row contains 5, and the largest is 5.
// Constraints:
//
// The number of nodes in the tree will be in the range [0, 104].
// -231 <= Node.val <= 231 - 1

func largestValues(root *TreeNode) []int {
	result := []int{}

	// Return an empty list if the root is null
	if root == nil {
		return result
	}

	// Initialize a queue for level order traversal
	queue := []*TreeNode{root}

	// Perform level order traversal
	for len(queue) > 0 {
		levelSize := len(queue)
		maxVal := math.MinInt64

		// Traverse all nodes at the current level
		for range levelSize {
			node := queue[0]
			queue = queue[1:]

			// Find the maximum value at the current level
			if node.Val > maxVal {
				maxVal = node.Val
			}

			// Add left and right children to the queue for the next level
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}

		// Store the largest value of the current level
		result = append(result, maxVal)
	}

	return result
}
