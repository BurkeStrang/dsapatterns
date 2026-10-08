namespace DsaPatterns.LevelOrderTraversal;

public class MaxWidthBinaryTreeTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int> Cases =>
        new()
        {
            {
                "Example 1: [1,2,3,4,null,null,5]",
                [1, 2, 3, 4, null, null, 5],
                4
            },
            {
                "Example 2: [1,2,3,4,null,5,6,null,7]",
                [1, 2, 3, 4, null, 5, 6, null, 7],
                4
            },
            { "Example 3: [1,2,null,3,4,5]", [1, 2, null, 3, 4, 5], 2 },
            { "Single node", [42], 1 },
            { "Empty tree", [], 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void WidthOfBinaryTree(string name, int?[] tree, int want)
    {
        int got = MaxWidthBinaryTree.WidthOfBinaryTree(Shared.ToTree(tree));

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
