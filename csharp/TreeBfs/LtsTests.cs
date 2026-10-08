namespace DsaPatterns.TreeBfs;

public class LtsTests
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
                    [2, 3],
                    [4, 5, 6],
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
    public void TraverseBasic(string name, int?[] tree, int[][] want)
    {
        List<List<int>> got = Lts.TraverseBasic(Shared.ToTree(tree));

        Assert.True(
            Shared.Format2D(got) == Shared.Format2D(want),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }
}
