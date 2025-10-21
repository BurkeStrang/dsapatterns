package treedfs

// Given a binary tree and a number ‘S’,
// find all paths from root-to-leaf such that the sum of all the node values of each path equals ‘S’.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

func findPaths(root *TreeNode, sum int) [][]int {
	allPaths := [][]int{}
	var currentPath []int
	findPathsRecursive(root, sum, currentPath, &allPaths)
	return allPaths
}

// findPathsRecursive to find paths recursively
func findPathsRecursive(currentNode *TreeNode, sum int, currentPath []int, allPaths *[][]int) {
	if currentNode == nil {
		return
	}

	// add the current node to the path
	currentPath = append(currentPath, currentNode.Val)

	// if the current node is a leaf and its value is equal to sum, save the current path
	if currentNode.Val == sum && currentNode.Left == nil && currentNode.Right == nil {
		path := make([]int, len(currentPath))
		copy(path, currentPath)
		*allPaths = append(*allPaths, path)
	} else {
		// traverse the left sub-tree
		findPathsRecursive(currentNode.Left, sum-currentNode.Val, currentPath, allPaths)
		// traverse the right sub-tree
		findPathsRecursive(currentNode.Right, sum-currentNode.Val, currentPath, allPaths)
	}

	// remove the current node from the path to backtrack,
	// we need to remove the current node while we are going up the recursive call stack.
	currentPath = currentPath[:len(currentPath)-1]
}
