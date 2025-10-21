package treebfs

// Given a root of the binary tree, connect each node with its level order successor.
// The last node of each level should point to a null node.
//
// Example 1:
// Input: root = [1, 2, 3, 4, 5, 6, 7]
// Output:
// [1 -> null]
// [2 -> 3 -> null]
// [4 -> 5 -> 6 -> 7 -> null]
// Explanation:
// The tree is traversed level by level using BFS. Each node is connected to its next right node at the same level. The last node of each level points to null.
//
// Example 2:
// Input: root = [12, 7, 1, 9, null, 10, 5]
// Output:
// [12 -> null]
// [7 -> 1 -> null]
// [9 -> 10 -> 5 -> null]
// Explanation:
// The nodes are connected to their next right sibling at the same level. The last node of each level points to null.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 2^12 - 1].
// -1000 <= Node.val <= 1000

func connect(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}

	queue := NewQueue()
	queue.Push(root)

	for !queue.Empty() {
		previousNode := (*TreeNode)(nil)
		levelSize := queue.data.Len()
		// connect all nodes of this level
		for range levelSize {
			var currentNode *TreeNode
			node, _ := queue.Front() // Get the front node of the queue
			currentNode = node
			queue.Pop()

			if previousNode != nil {
				previousNode.Next = currentNode
			}
			previousNode = currentNode

			// insert the children of current node in the queue
			if currentNode.Left != nil {
				queue.Push(currentNode.Left)
			}
			if currentNode.Right != nil {
				queue.Push(currentNode.Right)
			}
		}
	}
	return root
}
