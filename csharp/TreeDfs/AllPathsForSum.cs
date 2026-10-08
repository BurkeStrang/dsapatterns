namespace DsaPatterns.TreeDfs;

// Given a binary tree and a number ‘S’,
// find all paths from root-to-leaf such that the sum of all the node values of
// each path equals ‘S’.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

internal static class AllPathsForSum
{
    internal static List<List<int>> FindPaths(TreeNode? root, int sum)
    {
        List<List<int>> allPaths = [];
        List<int> currentPath = [];
        FindPathsRecursive(root, sum, currentPath, allPaths);
        return allPaths;
    }

    // FindPathsRecursive to find paths recursively
    private static void FindPathsRecursive(
        TreeNode? currentNode,
        int sum,
        List<int> currentPath,
        List<List<int>> allPaths
    )
    {
        if (currentNode == null)
        {
            return;
        }

        // add the current node to the path
        currentPath.Add(currentNode.Val);

        // if the current node is a leaf and its value is equal to sum, save
        // the current path
        if (
            currentNode.Val == sum
            && currentNode.Left == null
            && currentNode.Right == null
        )
        {
            allPaths.Add([.. currentPath]);
        }
        else
        {
            // traverse the left sub-tree
            FindPathsRecursive(
                currentNode.Left,
                sum - currentNode.Val,
                currentPath,
                allPaths
            );
            // traverse the right sub-tree
            FindPathsRecursive(
                currentNode.Right,
                sum - currentNode.Val,
                currentPath,
                allPaths
            );
        }

        // remove the current node from the path to backtrack, we need to
        // remove the current node while we are going up the recursive call
        // stack.
        currentPath.RemoveAt(currentPath.Count - 1);
    }
}
