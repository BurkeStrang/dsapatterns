package treedfs

// Given a binary tree, find the length of its diameter.
// The diameter of a tree is the number of nodes on the longest path between any two leaf nodes.
// The diameter of a tree may or may not pass through the root.
// Note: You can always assume that there are at least two leaf nodes in the given tree.
//
// Constraints:
// n == edges.length + 1
// 1 <= n <= 104
// 0 <= ai, bi < n
// ai != bi

func findDiameter(root *TreeNode) int {
	treeDiameter := 0
	calculateHeight(root, &treeDiameter)
	return treeDiameter
}

func calculateHeight(currentNode *TreeNode, treeDiameter *int) int {
	if currentNode == nil {
		return 0
	}

	leftTreeHeight := calculateHeight(currentNode.Left, treeDiameter)
	rightTreeHeight := calculateHeight(currentNode.Right, treeDiameter)

	// if the current node doesn't have a left or right subtree, we can't have
	// a path passing through it, since we need a leaf node on each side
	if leftTreeHeight != 0 && rightTreeHeight != 0 {
		// diameter at the current node will be equal to the height of left subtree +
		// the height of right sub-trees + '1' for the current node
		diameter := leftTreeHeight + rightTreeHeight + 1

		// update the global tree diameter
		*treeDiameter = max(*treeDiameter, diameter)
	}

	// height of the current node will be equal to the maximum of the heights of
	// left or right subtrees plus '1' for the current node
	return max(leftTreeHeight, rightTreeHeight) + 1
}
