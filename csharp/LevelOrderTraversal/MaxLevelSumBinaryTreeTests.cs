namespace DsaPatterns.LevelOrderTraversal;

public class MaxLevelSumBinaryTreeTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int> Cases =>
        new()
        {
            { "Example 1: [1,20,3,4,5,null,8]", [1, 20, 3, 4, 5, null, 8], 2 },
            {
                "Example 2: [10,5,-3,3,2,null,11,3,-2,null,1]",
                [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1],
                3
            },
            {
                "Example 3: [5,6,7,8,null,null,9,10]",
                [5, 6, 7, 8, null, null, 9, 10],
                3
            },
            { "Single node", [42], 1 },
            { "Negative values", [-1, -2, -3], 1 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MaxLevelSum(string name, int?[] tree, int want)
    {
        int got = MaxLevelSumBinaryTree.MaxLevelSum(Shared.ToTree(tree));

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
