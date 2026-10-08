namespace DsaPatterns.Subsets;

// Given a number n,
// write a function to return all structurally unique Binary Search Trees (BST),
// that can store values 1 to n?

// Example 1:
// input: 2
// output: [[1,null,2],[2,1]]

internal class TreeNode(int val)
{
    public int Val { get; set; } = val;
    public TreeNode? Left { get; set; }
    public TreeNode? Right { get; set; }
}

internal static class UniqueBst
{
    internal static List<TreeNode?> FindUniqueTrees(int n)
    {
        if (n <= 0)
        {
            return [];
        }

        return FindUniqueTreesRecursive(1, n);
    }

    // FindUniqueTreesRecursive is the recursive method to find unique trees
    private static List<TreeNode?> FindUniqueTreesRecursive(int start, int end)
    {
        List<TreeNode?> result = [];
        // base condition, return 'null' for an empty sub-tree
        // consider n=1, in this case we will have start=end=1, this means we
        // should have only one tree we will have two recursive calls,
        // FindUniqueTreesRecursive(1, 0) & (2, 1) both of these should return
        // 'null' for the left and the right child
        if (start > end)
        {
            result.Add(null);
            return result;
        }

        for (int i = start; i <= end; i++)
        {
            // making 'i' root of the tree
            List<TreeNode?> leftSubtrees = FindUniqueTreesRecursive(
                start,
                i - 1
            );
            List<TreeNode?> rightSubtrees = FindUniqueTreesRecursive(
                i + 1,
                end
            );
            foreach (TreeNode? leftTree in leftSubtrees)
            {
                foreach (TreeNode? rightTree in rightSubtrees)
                {
                    TreeNode root = new(i)
                    {
                        Left = leftTree,
                        Right = rightTree,
                    };
                    result.Add(root);
                }
            }
        }

        return result;
    }
}
