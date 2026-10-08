namespace DsaPatterns.TreeBfs;

// Given a root of the binary tree, connect each node with its level order
// successor.
// The last node of each level should point to a null node.
//
// Example 1:
// Input: root = [1, 2, 3, 4, 5, 6, 7]
// Output:
// [1 -> null]
// [2 -> 3 -> null]
// [4 -> 5 -> 6 -> 7 -> null]
// Explanation:
// The tree is traversed level by level using BFS. Each node is connected to its
// next right node at the same level. The last node of each level points to
// null.
//
// Example 2:
// Input: root = [12, 7, 1, 9, null, 10, 5]
// Output:
// [12 -> null]
// [7 -> 1 -> null]
// [9 -> 10 -> 5 -> null]
// Explanation:
// The nodes are connected to their next right sibling at the same level. The
// last node of each level points to null.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 2^12 - 1].
// -1000 <= Node.val <= 1000

internal static class ConnectLevelOrderSiblings
{
    internal static TreeNode? Connect(TreeNode? root)
    {
        if (root == null)
        {
            return root;
        }

        Queue<TreeNode> queue = new();
        queue.Enqueue(root);
        while (queue.Count > 0)
        {
            TreeNode? previousNode = null;
            int levelSize = queue.Count;
            // connect all nodes of this level
            for (int n = 0; n < levelSize; n++)
            {
                // Get the front node of the queue
                TreeNode currentNode = queue.Dequeue();
                if (previousNode != null)
                {
                    previousNode.Next = currentNode;
                }

                previousNode = currentNode;

                // insert the children of current node in the queue
                if (currentNode.Left != null)
                {
                    queue.Enqueue(currentNode.Left);
                }

                if (currentNode.Right != null)
                {
                    queue.Enqueue(currentNode.Right);
                }
            }
        }

        return root;
    }
}
