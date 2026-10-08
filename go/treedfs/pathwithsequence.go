package treedfs

// Given a binary tree and a number sequence,
// find if the sequence is present as a root-to-leaf path in the given tree.

func findPath(root *TreeNode, sequence []int) bool {
	if root == nil {
		return len(sequence) == 0
	}

	return findPathRecursive(root, sequence, 0)
}

func findPathRecursive(currentNode *TreeNode, sequence []int, sequenceIndex int) bool {
	if currentNode == nil {
		return false
	}

	if sequenceIndex >= len(sequence) || currentNode.Val != sequence[sequenceIndex] {
		return false
	}

	// if the current node is a leaf, and it is the end of the sequence, we have found a path!
	if currentNode.Left == nil && currentNode.Right == nil && sequenceIndex == len(sequence)-1 {
		return true
	}

	// recursively call to traverse the left and right sub-tree
	// return true if any of the two recursive call return true
	return findPathRecursive(currentNode.Left, sequence, sequenceIndex+1) ||
		findPathRecursive(currentNode.Right, sequence, sequenceIndex+1)
}
