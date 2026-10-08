namespace DsaPatterns.TreeBfs;

// Given a root of the binary tree, return an array containing nodes in its
// right view.
// The right view of a binary tree consists of nodes that are visible when the
// tree is viewed from the right side.
// For each level of the tree, the last node encountered in that level will be
// included in the right view.
//
// Example 1
// Input: root = [1, 2, 3, 4, 5, 6, 7]
// Expected Output: [1, 3, 7]
// Justification:
// The last node at level 0 is 1.
// The last node at level 1 is 3.
// The last node at level 2 is 7.
//
// Example 2
// Input: root = [12, 7, 1, null, 9, 10, 5, null, 3]
// Expected Output: [12, 1, 5, 3]
// Justification:
// The last node at level 0 is 12.
// The last node at level 1 is 1.
// The last node at level 2 is 5.
// The last node at level 3 is 3.
//
// Example 3
// Input: root = [8, 4, 9, 3, null, null, 10, 2]
// Expected Output: [8, 9, 10, 2]
// Justification:
// The last node at level 0 is 8.
// The last node at level 1 is 9.
// The last node at level 2 is 10.
// The last node at level 3 is 2.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

internal static class RightViewBinaryTree
{
    internal static List<int> RightView(TreeNode? root)
    {
        List<int> result = [];
        if (root == null)
        {
            return result;
        }

        Queue<TreeNode> queue = new();
        queue.Enqueue(root);

        while (queue.Count > 0)
        {
            int levelSize = queue.Count;
            TreeNode currentNode = queue.Peek();

            for (int n = 0; n < levelSize; n++)
            {
                currentNode = queue.Dequeue();

                if (currentNode.Left != null)
                {
                    queue.Enqueue(currentNode.Left);
                }

                if (currentNode.Right != null)
                {
                    queue.Enqueue(currentNode.Right);
                }
            }

            // Add the rightmost node of this level
            result.Add(currentNode.Val);
        }

        return result;
    }
}
