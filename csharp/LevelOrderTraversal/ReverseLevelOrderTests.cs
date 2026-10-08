namespace DsaPatterns.LevelOrderTraversal;

public class ReverseLevelOrderTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int[][]> Cases =>
        new()
        {
            {
                "Example 1",
                [1, 2, 3, 4, 5, 6, 7],
                [
                    [4, 5, 6, 7],
                    [2, 3],
                    [1],
                ]
            },
            {
                "Example 2",
                [12, 7, 1, null, 9, 10, 5],
                [
                    [9, 10, 5],
                    [7, 1],
                    [12],
                ]
            },
            {
                "Example 3",
                [6, 5, 2, null, null, 1, 6, 3, 56, null, 3],
                [
                    [3, 56, 3],
                    [1, 6],
                    [5, 2],
                    [6],
                ]
            },
            { "Empty tree", [], [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Traverse(string name, int?[] tree, int[][] want)
    {
        List<List<int>> got = ReverseLevelOrder.Traverse(Shared.ToTree(tree));

        Assert.True(
            Shared.Format2D(got) == Shared.Format2D(want),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }
}
