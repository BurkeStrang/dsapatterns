namespace DsaPatterns.TreeDfs;

// Given a binary tree where each node can only have a digit (0-9) value,
// each root-to-leaf path will represent a number.
// Find the total sum of all the numbers represented by all paths.

internal static class SumOfPathNums
{
    internal static int FindSumOfPathNumbers(TreeNode? root)
    {
        return FindPathSum(root, 0);
    }

    private static int FindPathSum(TreeNode? node, int currentSum)
    {
        if (node == null)
        {
            return 0;
        }

        // calculate the path number for the current node
        currentSum = (currentSum * 10) + node.Val;

        // if it's a leaf node, return the current path sum
        if (node.Left == null && node.Right == null)
        {
            return currentSum;
        }

        // traverse left and right subtrees
        return FindPathSum(node.Left, currentSum)
            + FindPathSum(node.Right, currentSum);
    }
}
