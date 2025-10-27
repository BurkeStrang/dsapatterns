package treedfs

import "math"

// Find the path with the maximum sum in a given binary tree.
// Write a function that returns the maximum sum.
// A path can be defined as a sequence of nodes between any two nodes and doesn’t necessarily pass through the root.
// The path must contain at least one node.

// Constraints:
// The number of nodes in the tree is in the range [1, 3 * 10^4].
// -1000 <= Node.val <= 1000

// Solution struct
type Solution struct {
	globalMaximumSum int
}

// NewSolution creates a new instance of Solution
func NewSolution() *Solution {
	return &Solution{globalMaximumSum: math.MinInt32}
}

// findMaximumPathSum starts the recursive process and returns the result
func (s *Solution) findMaximumPathSum(root *TreeNode) int {
	s.globalMaximumSum = math.MinInt32 // Reset the global maximum sum for each new tree
	s.findMaximumPathSumRecursive(root)
	return s.globalMaximumSum
}

// findMaximumPathSumRecursive calculates the maximum path sum recursively
func (s *Solution) findMaximumPathSumRecursive(currentNode *TreeNode) int {
	if currentNode == nil {
		return 0
	}

	maxPathSumFromLeft := s.findMaximumPathSumRecursive(currentNode.Left)
	maxPathSumFromRight := s.findMaximumPathSumRecursive(currentNode.Right)

	// ignore paths with negative sums
	maxPathSumFromLeft = max(maxPathSumFromLeft, 0)
	maxPathSumFromRight = max(maxPathSumFromRight, 0)

	// local maximum sum
	localMaximumSum := maxPathSumFromLeft + maxPathSumFromRight + currentNode.Val

	// update the global maximum sum
	s.globalMaximumSum = max(s.globalMaximumSum, localMaximumSum)

	// return the maximum sum of any path from the current node
	return max(maxPathSumFromLeft, maxPathSumFromRight) + currentNode.Val
}
