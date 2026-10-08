namespace DsaPatterns.LevelOrderTraversal;

// Given the root of a binary tree, return the bottom-up level order traversal
// of its nodes' values.
// (i.e., the lowest level comes first in left to right order.)
//
// Example 1
// Input: root = [1, 2, 3, 4, 5, 6, 7]
// Image
// Expected Output: [[4, 5, 6, 7], [2, 3], [1]]
// Justification:
// The third level has 4, 5, 6, and 7 nodes.
// The second level has 2 and 3 nodes.
// The first level has a single node with the value 1.
//
// Example 2
// Input: root = [12, 7, 1, null, 9, 10, 5]
// Image
// Expected Output: [[9, 10, 5], [7, 1], [12]]
// Justification:
// The third level has 9, 10, and 5 nodes.
// The second level has 7 and 1 nodes.
// The first level has a single node with the value 12.
//
// Example 3
// Input: root = [6,5,2,null,null,1,6,3,56,3]
// Image
// Expected Output: [[3,56,3],[1,6],[5,2],[6]]
// Justification:
// The fourth level has 3, 56, and 3 nodes.
// The third level has 1, and 6 nodes.
// The second level has 5 and 2 nodes.
// The first level has a single node with the value 6.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

internal static class ReverseLevelOrder
{
    internal static List<List<int>> Traverse(TreeNode? root)
    {
        List<List<int>> result = [];
        if (root == null)
        {
            return result;
        }

        Queue<TreeNode> queue = new();
        queue.Enqueue(root);
        while (queue.Count > 0)
        {
            int levelSize = queue.Count;
            List<int> currentLevel = new(levelSize);
            for (int n = 0; n < levelSize; n++)
            {
                TreeNode currentNode = queue.Dequeue();
                // add the node to the current level
                currentLevel.Add(currentNode.Val);
                // insert the children of current node to the queue
                if (currentNode.Left != null)
                {
                    queue.Enqueue(currentNode.Left);
                }

                if (currentNode.Right != null)
                {
                    queue.Enqueue(currentNode.Right);
                }
            }

            // append the current level at the beginning
            result.Insert(0, currentLevel);
        }

        return result;
    }
}
