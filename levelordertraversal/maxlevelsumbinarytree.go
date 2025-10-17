package levelordertraversal
import "math"

// You are given the root of a binary tree. The level of its root node is 1,
// the level of its children is 2, and so on.
// Return the level x where the sum of the values of all nodes is the highest.
// If there are multiple levels with the same maximum sum, return the smallest level number x.
//
// Example 1:
// Input: root = [1, 20, 3, 4, 5, null, 8]
// Image
// Expected Output: 2
// Explanation:
// Level 1 has nodes: [1] with sum = 1
// Level 2 has nodes: [20, 3] with sum = 20 + 3 = 23
// Level 3 has nodes: [4, 5, 8] with sum = 4 + 5 + 8 = 17
// The maximum sum is 23 at level 2.
//
// Example 2:
// Input: root = [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]
// Image
// Expected Output: 3
// Explanation:
// Level 1 has nodes: [10] with sum = 10
// Level 2 has nodes: [5, -3] with sum = 5 - 3 = 2
// Level 3 has nodes: [3, 2, 11] with sum = 3 + 2 + 11 = 16
// Level 4 has nodes: [3, -2, 1] with sum = 3 - 2 + 1 = 2
// The maximum sum is 16 at level 3.
//
// Example 3:
// Input: root = [5, 6, 7, 8, null, null, 9, null, null, 10]
// Image
// Expected Output: 2
// Explanation:
// Level 1 has nodes: [5] with sum = 5
// Level 2 has nodes: [6, 7] with sum = 6 + 7 = 13
// Level 3 has nodes: [8, 9] with sum = 8 + 9 = 17
// Level 4 has nodes: [10] with sum = 10
// The maximum sum is 17 at level 3.
//
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105

func maxLevelSum(root *TreeNode) int {
	if root == nil {
		return 0
	}

	queue := []*TreeNode{}
	queue = append(queue, root) // Add the root node to the queue

	maxSum := math.MinInt32
	resultLevel := 1 // To keep track of the level with the maximum sum
	currentLevel := 1 // Current level counter

	for len(queue) > 0 {
		levelSize := len(queue)
		currentSum := 0 // To calculate the sum of nodes at the current level

		for range levelSize {
			node := queue[0]
			queue = queue[1:]
			currentSum += node.Val // Add the node's value to the current sum

			// Add left child to the queue if it exists
			if node.Left != nil {
				queue = append(queue, node.Left)
			}

			// Add right child to the queue if it exists
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}

		// If the current level sum is greater than the maxSum found so far
		if currentSum > maxSum {
			maxSum = currentSum // Update maxSum
			resultLevel = currentLevel // Update resultLevel to the current level
		}

		currentLevel++ // Increment the level counter
	}

	return resultLevel
}
