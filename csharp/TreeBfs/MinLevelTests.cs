namespace DsaPatterns.TreeBfs;

public class MinLevelTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3, 4, 5], 2 },
            { "Example 2", [1, 2], 2 },
            { "Example 3", [1, 2, 3, 4, 5, 6], 3 },
            { "Example 4", [1], 1 },
            { "Empty tree", [], 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindDepth(string name, int?[] tree, int want)
    {
        int got = MinLevel.FindDepth(Shared.ToTree(tree));

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
