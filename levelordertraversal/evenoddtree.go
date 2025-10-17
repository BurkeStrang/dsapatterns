package levelordertraversal

// Given a binary tree, return true if it is an Even-Odd tree. Otherwise, return false.
// The Even-odd tree must follow below two rules:
//
// At every even-indexed level (starting from 0),
// all node values must be odd and arranged in strictly increasing order from left to right.
// At every odd-indexed level,
// all node values must be even and arranged in strictly decreasing order from left to right.
//
// Example 1
// Input:
//     1
//    / \
//   10  4
//  / \
// 3   7
// Expected Output: true
// Justification: The tree follows both conditions for each odd and even level. So, it is an odd-even tree.
//
// Example 2
// Input:
//
//     5
//    / \
//   9   3
//  /     \
// 12      8
// Expected Output: false
// Justification: Level 1 has Odd values 9 and 3 in decreasing order, but it should have even values. So, the tree is not an odd-even tree.
//
// Example 3
// Input:
//     7
//    / \
//   10  2
//  / \
// 12  8
// Expected Output: false
// Justification: At level 2 (even-indexed), the values are 12 and 8, which are even, but they should have odd values. So, the tree is not an odd-even tree.
//
// Constraints:
// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 10^6

func isEvenOddTree(root *TreeNode) bool {
	if root == nil {
		return true // Check if the tree is empty
	}

	queue := []*TreeNode{root}
	level := 0 // Start with level 0

	for len(queue) > 0 {
		size := len(queue)
		values := []int{} // Slice to store node values at current level

		for range size {
			node := queue[0]  // Get the next node in the queue
			queue = queue[1:] // Remove it from the queue
			values = append(values, node.Val)

			if node.Left != nil {
				queue = append(queue, node.Left) // Add left child to the queue if it exists
			}
			if node.Right != nil {
				queue = append(queue, node.Right) // Add right child to the queue if it exists
			}
		}

		// Check values for the current level
		if level%2 == 0 {
			for i := 0; i < len(values); i++ {
				if values[i]%2 == 0 || (i > 0 && values[i] <= values[i-1]) {
					return false // Even level: values must be odd and strictly increasing
				}
			}
		} else {
			for i := 0; i < len(values); i++ {
				if values[i]%2 != 0 || (i > 0 && values[i] >= values[i-1]) {
					return false // Odd level: values must be even and strictly decreasing
				}
			}
		}
		level++ // Move to the next level
	}
	return true // If all levels satisfy the conditions, return true
}
