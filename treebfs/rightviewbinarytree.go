package treebfs

// Given a root of the binary tree, return an array containing nodes in its right view.
// The right view of a binary tree consists of nodes that are visible when the tree is viewed from the right side.
// For each level of the tree, the last node encountered in that level will be included in the right view.
//
// Example 1
// Input: root = [1, 2, 3, 4, 5, 6, 7]
// Expected Output: [1, 3, 7]
// Justification:
// The last node at level 0 is 1.
// The last node at level 1 is 3.
// The last node at level 2 is 7.
//
// Example 2
// Input: root = [12, 7, 1, null, 9, 10, 5, null, 3]
// Expected Output: [12, 1, 5, 3]
// Justification:
// The last node at level 0 is 12.
// The last node at level 1 is 1.
// The last node at level 2 is 5.
// The last node at level 3 is 3.
//
// Example 3
// Input: root = [8, 4, 9, 3, null, null, 10, 2]
// Expected Output: [8, 9, 10, 2]
// Justification:
// The last node at level 0 is 8.
// The last node at level 1 is 9.
// The last node at level 2 is 10.
// The last node at level 3 is 2.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100


func rightView(root *TreeNode) []int {
	var result []int
	if root == nil {
		return result
	}

	queue := []*TreeNode{root}

	for len(queue) > 0 {
		levelSize := len(queue)
		var currentNode *TreeNode

		for range levelSize {
			currentNode = queue[0]
			queue = queue[1:]

			if currentNode.Left != nil {
				queue = append(queue, currentNode.Left)
			}
			if currentNode.Right != nil {
				queue = append(queue, currentNode.Right)
			}
		}

		// Add the rightmost node of this level
		result = append(result, currentNode.Val)
	}

	return result
}
