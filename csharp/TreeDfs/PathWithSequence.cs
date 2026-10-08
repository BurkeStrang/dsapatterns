namespace DsaPatterns.TreeDfs;

// Given a binary tree and a number sequence,
// find if the sequence is present as a root-to-leaf path in the given tree.

internal static class PathWithSequence
{
    internal static bool FindPath(TreeNode? root, int[] sequence)
    {
        if (root == null)
        {
            return sequence.Length == 0;
        }

        return FindPathRecursive(root, sequence, 0);
    }

    private static bool FindPathRecursive(
        TreeNode? currentNode,
        int[] sequence,
        int sequenceIndex
    )
    {
        if (currentNode == null)
        {
            return false;
        }

        if (
            sequenceIndex >= sequence.Length
            || currentNode.Val != sequence[sequenceIndex]
        )
        {
            return false;
        }

        // if the current node is a leaf, and it is the end of the sequence, we
        // have found a path!
        if (
            currentNode.Left == null
            && currentNode.Right == null
            && sequenceIndex == sequence.Length - 1
        )
        {
            return true;
        }

        // recursively call to traverse the left and right sub-tree
        // return true if any of the two recursive call return true
        return FindPathRecursive(currentNode.Left, sequence, sequenceIndex + 1)
            || FindPathRecursive(
                currentNode.Right,
                sequence,
                sequenceIndex + 1
            );
    }
}
