package treebfs

// Given a root of the binary tree, find the minimum depth of a binary tree.
// The minimum depth is the number of nodes along the shortest path from the root node to the nearest leaf node.
//
// Example 1
// Input: [1,2,3,4,5]
// Output: 2
//
// Example 2
// Input: [1,2]
// Output: 2
//
// Example 3
// Input: [1,2,3,4,5,6]
// Output: 3
//
// Example 4
// Input: [1]
// Output: 1
//
// Constraints:
// The number of nodes in the tree is in the range [0, 10^5].
// -1000 <= Node.val <= 1000

func findDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	queue := make([]*TreeNode, 0)
	queue = append(queue, root)
	minimumTreeDepth := 0

	for len(queue) > 0 {
		minimumTreeDepth++
		levelSize := len(queue)
		for range levelSize {
			currentNode := queue[0]
			queue = queue[1:]

			// check if this is a leaf node
			if currentNode.Left == nil && currentNode.Right == nil {
				return minimumTreeDepth
			}

			// insert the children of current node in the queue
			if currentNode.Left != nil {
				queue = append(queue, currentNode.Left)
			}
			if currentNode.Right != nil {
				queue = append(queue, currentNode.Right)
			}
		}
	}
	return minimumTreeDepth
}
