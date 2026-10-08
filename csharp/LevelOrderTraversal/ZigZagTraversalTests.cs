namespace DsaPatterns.LevelOrderTraversal;

public class ZigZagTraversalTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int[][]> Cases =>
        new()
        {
            {
                "Example 1: [1,2,3,4,5,null,6]",
                [1, 2, 3, 4, 5, null, 6],
                [
                    [1],
                    [3, 2],
                    [4, 5, 6],
                ]
            },
            {
                "Example 2: [7,4,8,2,5,null,9,null,3]",
                [7, 4, 8, 2, 5, null, 9, null, 3],
                [
                    [7],
                    [8, 4],
                    [2, 5, 9],
                    [3],
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
    public void TraverseZigZag(string name, int?[] tree, int[][] want)
    {
        List<List<int>> got = ZigZagTraversal.TraverseZigZag(
            Shared.ToTree(tree)
        );

        Assert.True(
            Shared.Format2D(got) == Shared.Format2D(want),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }
}
