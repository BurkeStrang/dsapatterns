namespace DsaPatterns.TreeBfs;

// Given a root of the binary tree, find the minimum depth of a binary tree.
// The minimum depth is the number of nodes along the shortest path from the
// root node to the nearest leaf node.
//
// Example 1
// Input: [1,2,3,4,5]
// Output: 2
//
// Example 2
// Input: [1,2]
// Output: 2
//
// Example 3
// Input: [1,2,3,4,5,6]
// Output: 3
//
// Example 4
// Input: [1]
// Output: 1
//
// Constraints:
// The number of nodes in the tree is in the range [0, 10^5].
// -1000 <= Node.val <= 1000

internal static class MinLevel
{
    internal static int FindDepth(TreeNode? root)
    {
        if (root == null)
        {
            return 0;
        }

        Queue<TreeNode> queue = new();
        queue.Enqueue(root);
        int minimumTreeDepth = 0;
        while (queue.Count > 0)
        {
            minimumTreeDepth++;
            int levelSize = queue.Count;
            for (int n = 0; n < levelSize; n++)
            {
                TreeNode currentNode = queue.Dequeue();

                // check if this is a leaf node
                if (currentNode.Left == null && currentNode.Right == null)
                {
                    return minimumTreeDepth;
                }

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

        return minimumTreeDepth;
    }
}
