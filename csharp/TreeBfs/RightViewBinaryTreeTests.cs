namespace DsaPatterns.TreeBfs;

public class RightViewBinaryTreeTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int[]> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3, 4, 5, 6, 7], [1, 3, 7] },
            { "Example 2", [12, 7, 1, null, 9, 10, 5, null, 3], [12, 1, 5, 3] },
            { "Example 3", [8, 4, 9, 3, null, null, 10, 2], [8, 9, 10, 2] },
            { "Empty tree", [], [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void RightView(string name, int?[] tree, int[] want)
    {
        List<int> got = RightViewBinaryTree.RightView(Shared.ToTree(tree));

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
