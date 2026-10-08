namespace DsaPatterns.TreeDfs;

// Given a binary tree, find the length of its diameter.
// The diameter of a tree is the number of nodes on the longest path between any
// two leaf nodes.
// The diameter of a tree may or may not pass through the root.
// Note: You can always assume that there are at least two leaf nodes in the
// given tree.
//
// Constraints:
// n == edges.length + 1
// 1 <= n <= 104
// 0 <= ai, bi < n
// ai != bi

internal static class TreeDiameter
{
    internal static int FindDiameter(TreeNode? root)
    {
        int treeDiameter = 0;
        CalculateHeight(root, ref treeDiameter);
        return treeDiameter;
    }

    private static int CalculateHeight(
        TreeNode? currentNode,
        ref int treeDiameter
    )
    {
        if (currentNode == null)
        {
            return 0;
        }

        int leftTreeHeight = CalculateHeight(
            currentNode.Left,
            ref treeDiameter
        );
        int rightTreeHeight = CalculateHeight(
            currentNode.Right,
            ref treeDiameter
        );

        // if the current node doesn't have a left or right subtree, we can't
        // have a path passing through it, since we need a leaf node on each
        // side
        if (leftTreeHeight != 0 && rightTreeHeight != 0)
        {
            // diameter at the current node will be equal to the height of left
            // subtree + the height of right sub-trees + '1' for the current
            // node
            int diameter = leftTreeHeight + rightTreeHeight + 1;

            // update the global tree diameter
            treeDiameter = Math.Max(treeDiameter, diameter);
        }

        // height of the current node will be equal to the maximum of the
        // heights of left or right subtrees plus '1' for the current node
        return Math.Max(leftTreeHeight, rightTreeHeight) + 1;
    }
}
