package treedfs

// Given a root of the binary tree and an integer S,
// return true if the tree has a path from root-to-leaf such that the sum of all the node values of that path equals S.
// Otherwise, return false.
//
// Example 1:
// Input: root = [1, 2, 3, 4, 5, 6, 7], S = 10
// Expected Output: true
// Justification: The tree has 1 -> 3 -> 6 root-to-leaf path having sum equal to 10.
//
// Example 2:
// Input: root = [12, 7, 1, 9, null, 10, 5], S = 23
// Expected Output: true
// Justification: The tree has 12 -> 1 -> 10 root-to-leaf path having sum equal to 23.
//
// Example 3:
// Input: root = [12, 7, 1, 9, null, 10, 5], S = 16
// Expected Output: false
// Justification: The tree doesn't have root-to-leaf path having sum equal to 16.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000



func hasPath(root *TreeNode, sum int) bool {
    if root == nil {
        return false
    }

    // if the current node is leaf and its value is equal to the sum, we've found a path
    if root.Val == sum && root.Left == nil && root.Right == nil {
        return true
    }

    // recursively call to traverse the left and right sub-tree
    // return true if any of the two recursive call return true
    return hasPath(root.Left, sum-root.Val) || hasPath(root.Right, sum-root.Val)
}
