namespace DsaPatterns.TreeDfs;

public class TreeDiameterTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int> Cases =>
        new()
        {
            { "Single node", [1], 0 },
            // Path: 4-2-1-3 or 5-2-1-3
            //            1
            //           / \
            //          2   3
            //         / \
            //        4   5
            { "Simple tree", [1, 2, 3, 4, 5], 4 },
            // Path: 4-1-2-3
            //       1
            //      / \
            //     4   2
            //          \
            //           3
            { "Linear tree", [1, 4, 2, null, null, null, 3], 4 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindDiameter(string name, int?[] tree, int want)
    {
        int got = TreeDiameter.FindDiameter(Shared.ToTree(tree));

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
