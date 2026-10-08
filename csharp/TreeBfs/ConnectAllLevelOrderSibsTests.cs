namespace DsaPatterns.TreeBfs;

public class ConnectAllLevelOrderSibsTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int[]> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3, 4, 5, 6, 7], [1, 2, 3, 4, 5, 6, 7] },
            { "Example 2", [12, 7, 1, 9, null, 10, 5], [12, 7, 1, 9, 10, 5] },
            { "Empty tree", [], [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void ConnectAll(string name, int?[] tree, int[] want)
    {
        TreeNode? gotRoot = ConnectAllLevelOrderSibs.ConnectAll(
            Shared.ToTree(tree)
        );

        List<int> got = FlattenNext(gotRoot);
        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }

    // FlattenNext traverses the tree using Next pointers and returns values
    // in order.
    private static List<int> FlattenNext(TreeNode? root)
    {
        List<int> result = [];
        TreeNode? curr = root;
        while (curr != null)
        {
            result.Add(curr.Val);
            curr = curr.Next;
        }

        return result;
    }
}
