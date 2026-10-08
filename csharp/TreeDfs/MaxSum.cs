namespace DsaPatterns.TreeDfs;

// Find the path with the maximum sum in a given binary tree.
// Write a function that returns the maximum sum.
// A path can be defined as a sequence of nodes between any two nodes and
// doesn’t necessarily pass through the root.
// The path must contain at least one node.

// Constraints:
// The number of nodes in the tree is in the range [1, 3 * 10^4].
// -1000 <= Node.val <= 1000

// Solution struct

internal class MaxSum
{
    private int globalMaximumSum = int.MinValue;

    // FindMaximumPathSum starts the recursive process and returns the result
    internal int FindMaximumPathSum(TreeNode? root)
    {
        // Reset the global maximum sum for each new tree
        globalMaximumSum = int.MinValue;
        FindMaximumPathSumRecursive(root);
        return globalMaximumSum;
    }

    // FindMaximumPathSumRecursive calculates the maximum path sum recursively
    private int FindMaximumPathSumRecursive(TreeNode? currentNode)
    {
        if (currentNode == null)
        {
            return 0;
        }

        int maxPathSumFromLeft = FindMaximumPathSumRecursive(currentNode.Left);
        int maxPathSumFromRight = FindMaximumPathSumRecursive(
            currentNode.Right
        );

        // ignore paths with negative sums
        maxPathSumFromLeft = Math.Max(maxPathSumFromLeft, 0);
        maxPathSumFromRight = Math.Max(maxPathSumFromRight, 0);

        // local maximum sum
        int localMaximumSum =
            maxPathSumFromLeft + maxPathSumFromRight + currentNode.Val;

        // update the global maximum sum
        globalMaximumSum = Math.Max(globalMaximumSum, localMaximumSum);

        // return the maximum sum of any path from the current node
        return Math.Max(maxPathSumFromLeft, maxPathSumFromRight)
            + currentNode.Val;
    }
}
