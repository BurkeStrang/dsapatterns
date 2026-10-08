namespace DsaPatterns.TreeDfs;

public class SumOfPathNumsTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3], 25 }, // Paths: 12, 13 => 12+13=25
            // Paths: 101, 106, 115 => 101+106+115=322
            //                       1
            //                     /   \
            //                    0     1
            //                   / \     \
            //                  1   6     5
            { "Example 2", [1, 0, 1, 1, 6, null, 5], 322 },
            { "Single node", [5], 5 },
            { "Empty tree", [], 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindSumOfPathNumbers(string name, int?[] tree, int want)
    {
        int got = SumOfPathNums.FindSumOfPathNumbers(Shared.ToTree(tree));

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
