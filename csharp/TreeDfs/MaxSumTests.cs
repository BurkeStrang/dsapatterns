namespace DsaPatterns.TreeDfs;

public class MaxSumTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int> Cases =>
        new()
        {
            { "simple tree", [1, 2, 3], 6 }, // 2 + 1 + 3
            // 15 + 20 + 7
            {
                "tree with negative values",
                [-10, 9, 20, null, null, 15, 7],
                42
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMaximumPathSum(string name, int?[] tree, int want)
    {
        MaxSum solution = new();

        int got = solution.FindMaximumPathSum(Shared.ToTree(tree));

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
