package levelordertraversal

func traverseZigZag(root *TreeNode) [][]int {
	result := make([][]int, 0)
	if root == nil {
		return result
	}

	queue := make([]*TreeNode, 0)
	queue = append(queue, root)
	leftToRight := true
	for len(queue) > 0 {
		levelSize := len(queue)
		currentLevel := make([]int, 0)
		for range levelSize {
			currentNode := queue[0]
			queue = queue[1:]

			// add the node to the current level based on the traverse direction
			if leftToRight {
				currentLevel = append(currentLevel, currentNode.Val)
			} else {
				currentLevel = append([]int{currentNode.Val}, currentLevel...)
			}

			// insert the children of current node in the queue
			if currentNode.Left != nil {
				queue = append(queue, currentNode.Left)
			}
			if currentNode.Right != nil {
				queue = append(queue, currentNode.Right)
			}
		}
		result = append(result, currentLevel)
		// reverse the traversal direction
		leftToRight = !leftToRight
	}

	return result
}
