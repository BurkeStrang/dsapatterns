package treedfs

// Given a binary tree and a number sequence,
// find if the sequence is present as a root-to-leaf path in the given tree.

func findPath(root *TreeNode, sequence []int) bool {
	var currentPath []int
	return findSequenceRecursive(root, sequence, currentPath)
}

func findSequenceRecursive(currentNode *TreeNode, sequence []int, currentPath []int) bool {
	if currentNode == nil {
		return false
	}

	currentPath = append(currentPath, currentNode.Val)

	if currentNode.Left == nil && currentNode.Right == nil {
		if equalArray(sequence, currentPath) {
			return true
		}
	}
	return findSequenceRecursive(currentNode.Left, sequence, currentPath) ||
		findSequenceRecursive(currentNode.Right, sequence, currentPath)
}
