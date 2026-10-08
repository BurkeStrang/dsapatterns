namespace DsaPatterns.TreeDfs;

public class CountPathsSumTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int, int> Cases =>
        new()
        {
            // Paths: [1,2], [3]
            { "Example 1: Single path", [1, 2, 3], 3, 2 },
            // Paths: [5,3], [5,2,1], [10,-3,11]
            {
                "Example 2: Multiple paths",
                [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1],
                8,
                3
            },
            { "Example 3: No path", [1, 2], 100, 0 },
            { "Example 4: Empty tree", [], 0, 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CountPaths(string name, int?[] tree, int targetSum, int want)
    {
        int got = CountPathsSum.CountPaths(Shared.ToTree(tree), targetSum);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
