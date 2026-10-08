namespace DsaPatterns.TreeBfs;

// Given a binary tree,Given a binary tree, populate an array to represent its
// level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.
// populate an array to represent its level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.

internal static class LevelAverages
{
    internal static List<double> LevelAverage(TreeNode? root)
    {
        List<double> result = [];
        if (root == null)
        {
            return result;
        }

        Queue<TreeNode> queue = new();
        queue.Enqueue(root);
        while (queue.Count > 0)
        {
            int levelSize = queue.Count;
            double levelSum = 0.0;
            for (int n = 0; n < levelSize; n++)
            {
                TreeNode currentNode = queue.Dequeue();
                // add the node's value to the running sum
                levelSum += currentNode.Val;
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

            // append the current level's average to the result
            result.Add(levelSum / levelSize);
        }

        return result;
    }
}
