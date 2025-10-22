package treedfs

// Given a binary tree where each node can only have a digit (0-9) value,
// each root-to-leaf path will represent a number.
// Find the total sum of all the numbers represented by all paths.

func findSumOfPathNumbers(root *TreeNode) int {
	return findPathSum(root, 0)
}

func findPathSum(node *TreeNode, currentSum int) int {
	if node == nil {
		return 0
	}

	// calculate the path number for the current node
	currentSum = currentSum*10 + node.Val

	// if it's a leaf node, return the current path sum
	if node.Left == nil && node.Right == nil {
		return currentSum
	}

	// traverse left and right subtrees
	return findPathSum(node.Left, currentSum) + findPathSum(node.Right, currentSum)
}
