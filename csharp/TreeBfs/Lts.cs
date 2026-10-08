namespace DsaPatterns.TreeBfs;

// Given a binary tree,Given a binary tree, populate an array to represent its
// level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.
// populate an array to represent its level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.

internal static class Lts
{
    internal static List<List<int>> TraverseBasic(TreeNode? root)
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

            result.Add(currentLevel);
        }

        return result;
    }
}
