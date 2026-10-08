namespace DsaPatterns.LevelOrderTraversal;

public class NArrayTreeTests
{
    // trees are given in level order, with null ending each group of children
    public static TheoryData<string, int?[], int[][]> Cases =>
        new()
        {
            {
                "Example 1: [1,null,2,3,4,null,5,6]",
                [1, null, 2, 3, 4, null, 5, 6],
                [
                    [1],
                    [2, 3, 4],
                    [5, 6],
                ]
            },
            {
                "Single node",
                [42],
                [
                    [42],
                ]
            },
            { "Empty tree", [], [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void LevelOrder(string name, int?[] tree, int[][] want)
    {
        List<List<int>> got = NArrayTree.LevelOrder(Shared.ToNAryTree(tree));

        Assert.True(
            Shared.Format2D(got) == Shared.Format2D(want),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }
}
