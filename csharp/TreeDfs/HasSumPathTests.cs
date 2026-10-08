namespace DsaPatterns.TreeDfs;

public class HasSumPathTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int, bool> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3, 4, 5, 6, 7], 10, true },
            { "Example 2", [12, 7, 1, 9, null, 10, 5], 23, true },
            { "Example 3", [12, 7, 1, 9, null, 10, 5], 16, false },
            { "Empty tree", [], 0, false },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void HasPath(string name, int?[] tree, int sum, bool want)
    {
        bool got = HasSumPath.HasPath(Shared.ToTree(tree), sum);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
