namespace DsaPatterns.LevelOrderTraversal;

// Example 1:
// input: root = [3,9,20,null,null,15,7]
// output: [[3],[20,9],[15,7]]

internal static class ZigZagTraversal
{
    internal static List<List<int>> TraverseZigZag(TreeNode? root)
    {
        List<List<int>> result = [];
        if (root == null)
        {
            return result;
        }

        Queue<TreeNode> queue = new();
        queue.Enqueue(root);
        bool leftToRight = true;
        while (queue.Count > 0)
        {
            int levelSize = queue.Count;
            List<int> currentLevel = [];
            for (int n = 0; n < levelSize; n++)
            {
                TreeNode currentNode = queue.Dequeue();

                // add the node to the current level based on the traverse
                // direction
                if (leftToRight)
                {
                    currentLevel.Add(currentNode.Val);
                }
                else
                {
                    currentLevel.Insert(0, currentNode.Val);
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

            result.Add(currentLevel);
            // reverse the traversal direction
            leftToRight = !leftToRight;
        }

        return result;
    }
}
