namespace DsaPatterns.TreeBfs;

public class LevelOrderSuccesorTests
{
    // trees are given in level order, with null for a missing child; want is
    // compared by value, with 0 meaning no successor
    public static TheoryData<string, int?[], int, int> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3, 4, 5], 3, 4 },
            { "Example 2", [12, 7, 1, 9, null, 10, 5], 9, 10 },
            { "Example 3", [12, 7, 1, 9, null, 10, 5], 12, 7 },
            { "No successor (last node)", [1, 2], 2, 0 },
            { "Empty tree", [], 1, 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindSuccessor(string name, int?[] tree, int key, int want)
    {
        TreeNode? successor = LevelOrderSuccesor.FindSuccessor(
            Shared.ToTree(tree),
            key
        );

        int got = successor?.Val ?? 0;
        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
