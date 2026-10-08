namespace DsaPatterns.TreeDfs;

public class AllPathsForSumTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int, int[][]> Cases =>
        new()
        {
            {
                "Example 1",
                [1, 2, 3, 4, 5, 6, 7],
                10,
                [
                    [1, 3, 6],
                ]
            },
            {
                "Example 2",
                [12, 7, 1, 9, null, 10, 5],
                23,
                [
                    [12, 1, 10],
                ]
            },
            {
                "No path",
                [5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1],
                100,
                []
            },
            { "Empty tree", [], 0, [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindPaths(string name, int?[] tree, int sum, int[][] want)
    {
        List<List<int>> got = AllPathsForSum.FindPaths(
            Shared.ToTree(tree),
            sum
        );

        Assert.True(
            Shared.Format2D(got) == Shared.Format2D(want),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }
}
