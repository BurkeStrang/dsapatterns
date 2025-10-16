package levelordertraversal

// Given the root of a binary tree, find the maximum width of the tree.
// The maximum width is the widest level in the tree.
// The width of a level is the number of nodes between the leftmost and rightmost non-null nodes, where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
// You can assume that the result will fit within a 32-bit signed integer.
//
// Example 1
// Input: root = [1, 2, 3, 4, null, null, 5]
// Image
// Output: 4
// Justification: The maximum width is at the last level between nodes 4 and 5. It counts four positions: [4, null, null, 5].
//
// Example 2
// Input: root = [1, 2, 3, 4, null, 5, 6, null, 7]
// Image
// Output: 4
// Justification: The maximum width is between nodes 4 and 6 at level 3, counting four positions: [4, null, 5, 6].
//
// Example 3
// Input: root = [1, 2, null, 3, 4, null, null, 5]
// Image
// Output: 2
// Justification: The maximum width is at the third level, between nodes 3 and 4. It counts two positions: [3, 4].
//
// Constraints:
// The number of nodes in the tree is in the range [1, 3000].
// -100 <= Node.val <= 100

// Method to find the maximum width of the binary tree
func widthOfBinaryTree(root *TreeNode) int {
	if root == nil {
		return 0
	}

	queue := []Pair{}
	queue = append(queue, Pair{root, 0}) // Add the root node with position 0
	maxWidth := 0                        // Initialize maximum width

	// Level order traversal using queue
	for len(queue) > 0 {
		size := len(queue)
		minIndex := queue[0].index // Get the minimum index at this level to normalize positions
		first, last := 0, 0

		for i := range size {
			current := queue[0]
			queue = queue[1:]
			node := current.node
			index := current.index - minIndex // Normalize the index to prevent overflow

			// Record the first and last positions at the current level
			if i == 0 {
				first = index
			}
			if i == size-1 {
				last = index
			}

			// Enqueue left child with the correct position if it exists
			if node.Left != nil {
				queue = append(queue, Pair{node.Left, 2 * index})
			}

			// Enqueue right child with the correct position if it exists
			if node.Right != nil {
				queue = append(queue, Pair{node.Right, 2*index + 1})
			}
		}

		// Calculate the width of the current level and update maxWidth
		maxWidth = max(maxWidth, last-first+1)
	}

	return maxWidth
}
