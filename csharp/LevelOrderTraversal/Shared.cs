namespace DsaPatterns.LevelOrderTraversal;

internal class NAryNode(int val)
{
    public int Val { get; set; } = val;
    public List<NAryNode> Children { get; } = [];
}

internal class TreeNode(int val)
{
    public int Val { get; set; } = val;
    public TreeNode? Left { get; set; }
    public TreeNode? Right { get; set; }
}

// Shared helpers for the level order traversal problems.
internal static class Shared
{
    // Builds a binary tree from its level order values, with null marking a
    // missing child (e.g. [1, 2, 3, null, 4]), to keep test data compact.
    internal static TreeNode? ToTree(int?[] vals)
    {
        if (vals.Length == 0 || vals[0] is not int rootVal)
        {
            return null;
        }

        TreeNode root = new(rootVal);
        Queue<TreeNode> queue = new();
        queue.Enqueue(root);
        int i = 1;
        while (queue.Count > 0 && i < vals.Length)
        {
            TreeNode node = queue.Dequeue();
            if (vals[i] is int leftVal)
            {
                node.Left = new TreeNode(leftVal);
                queue.Enqueue(node.Left);
            }

            i++;
            if (i < vals.Length && vals[i] is int rightVal)
            {
                node.Right = new TreeNode(rightVal);
                queue.Enqueue(node.Right);
            }

            i++;
        }

        return root;
    }

    // Builds an n-ary tree from its level order values, where each group of
    // children is separated by null (e.g. [1, null, 2, 3, 4, null, 5, 6]).
    internal static NAryNode? ToNAryTree(int?[] vals)
    {
        if (vals.Length == 0 || vals[0] is not int rootVal)
        {
            return null;
        }

        NAryNode root = new(rootVal);
        Queue<NAryNode> queue = new();
        queue.Enqueue(root);
        int i = 2; // skip the root and the null that follows it
        while (queue.Count > 0 && i < vals.Length)
        {
            NAryNode node = queue.Dequeue();
            while (i < vals.Length && vals[i] is int childVal)
            {
                NAryNode child = new(childVal);
                node.Children.Add(child);
                queue.Enqueue(child);
                i++;
            }

            i++; // skip the null that ends this group of children
        }

        return root;
    }

    internal static string Format(IEnumerable<int> nums)
    {
        return $"[{string.Join(", ", nums)}]";
    }

    internal static string Format2D(IEnumerable<IEnumerable<int>> rows)
    {
        return $"[{string.Join(", ", rows.Select(Format))}]";
    }
}
