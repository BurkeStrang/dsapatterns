namespace DsaPatterns.Subsets;

public class UniqueBstTests
{
    // each expected tree is written in level order, with null for a missing
    // child
    public static TheoryData<string, int, string[]> Cases =>
        new()
        {
            { "Example 1", 2, ["[1, null, 2]", "[2, 1]"] },
            {
                "Example 2",
                3,
                [
                    "[1, null, 2, null, 3]",
                    "[1, null, 3, 2]",
                    "[2, 1, 3]",
                    "[3, 1, null, null, 2]",
                    "[3, 2, null, 1]",
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindUniqueTrees(string name, int n, string[] want)
    {
        List<TreeNode?> trees = UniqueBst.FindUniqueTrees(n);

        List<string> got = trees.Select(LevelOrder).ToList();
        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }

    // LevelOrder writes a tree in level order, with null for a missing child
    // and trailing nulls left off.
    private static string LevelOrder(TreeNode? root)
    {
        List<string> vals = [];
        Queue<TreeNode?> queue = new();
        queue.Enqueue(root);
        while (queue.Count > 0)
        {
            TreeNode? node = queue.Dequeue();
            if (node == null)
            {
                vals.Add("null");
                continue;
            }

            vals.Add(node.Val.ToString());
            queue.Enqueue(node.Left);
            queue.Enqueue(node.Right);
        }

        while (vals.Count > 0 && vals[^1] == "null")
        {
            vals.RemoveAt(vals.Count - 1);
        }

        return Shared.Format(vals);
    }
}
