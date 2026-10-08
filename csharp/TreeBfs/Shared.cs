namespace DsaPatterns.TreeBfs;

internal class TreeNode(int val)
{
    public int Val { get; set; } = val;
    public TreeNode? Left { get; set; }
    public TreeNode? Right { get; set; }
    public TreeNode? Next { get; set; }
}

// Shared helpers for the tree BFS problems.
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

    internal static bool EqualDoubles(
        IReadOnlyList<double> a,
        IReadOnlyList<double> b,
        double epsilon = 1e-9
    )
    {
        if (a.Count != b.Count)
        {
            return false;
        }

        for (int i = 0; i < a.Count; i++)
        {
            if (Math.Abs(a[i] - b[i]) > epsilon)
            {
                return false;
            }
        }

        return true;
    }

    internal static string Format<T>(IEnumerable<T> items)
    {
        return $"[{string.Join(", ", items)}]";
    }

    internal static string Format2D(IEnumerable<IEnumerable<int>> rows)
    {
        return $"[{string.Join(", ", rows.Select(Format))}]";
    }
}
