package bfs

// Given a binary tree,Given a binary tree, populate an array to represent its level-by-level traversal.
// You should populate the values of all nodes of each level from left to right in separate sub-arrays.
// populate an array to represent its level-by-level traversal.
// You should populate the values of all nodes of each level from left to right in separate sub-arrays.

func levelAverage(root *TreeNode) []float64 {
	result := []float64{}
	if root == nil {
		return result
	}

	queue := []*TreeNode{}
	queue = append(queue, root)
	for len(queue) > 0 {
		levelSize := len(queue)
		levelSum := 0.0
		for i := 0; i < levelSize; i++ {
			currentNode := queue[0]
			queue = queue[1:]
			// add the node's value to the running sum
			levelSum += float64(currentNode.Val)
			// insert the children of current node to the queue
			if currentNode.Left != nil {
				queue = append(queue, currentNode.Left)
			}
			if currentNode.Right != nil {
				queue = append(queue, currentNode.Right)
			}
		}
		// append the current level's average to the result array
		result = append(result, levelSum/float64(levelSize))
	}
	return result
}

