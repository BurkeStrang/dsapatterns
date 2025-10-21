package treebfs

// Given a root of the binary tree and an integer key,
// find the level order successor of the node containing the given key as a value in the tree.
// The level order successor is the node that appears right after the given node in the level order traversal.
//
// Example 1
// Input: root = [1, 2, 3, 4, 5], key = 3
// Output: 4
// Explanation: The level-order traversal of the tree is [1, 2, 3, 4, 5]. The successor of 3 in this order is 4.
//
// Example 2
// Input: root = [12, 7, 1, 9, null, 10, 5], key = 9
// Output: 10
// Explanation: The level-order traversal of the tree is [12, 7, 1, 9, 10, 5]. The successor of 9 in this order is 10.
//
// Example 3
// Input: root = [12, 7, 1, 9, null, 10, 5], key = 12
// Image
// Output: 7
// Explanation: The level-order traversal of the tree is [12, 7, 1, 9, 10]. The successor of 12 in this order is 7.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 105].
// -1000 <= Node.val <= 1000

func FindSuccessor(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return nil
	}

	queue := NewQueue()
	queue.Push(root)

	for !queue.Empty() {
		var currentNode *TreeNode
		node, _ := queue.Front() // Get the front node of the queue
		currentNode = node
		queue.Pop()

		// insert the children of current node in the queue
		if currentNode.Left != nil {
			queue.Push(currentNode.Left)
		}
		if currentNode.Right != nil {
			queue.Push(currentNode.Right)
		}

		// break if we have found the key
		if currentNode.Val == key {
			break
		}
	}

	if !queue.Empty() {
		var nextNode *TreeNode
		n1, _ := queue.Front() // Get the front node of the queue
		nextNode = n1
		return nextNode
	}
	return nil
}
