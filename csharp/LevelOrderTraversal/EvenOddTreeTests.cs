namespace DsaPatterns.LevelOrderTraversal;

public class EvenOddTreeTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], bool> Cases =>
        new()
        {
            { "Example 1: Valid Even-Odd Tree", [1, 10, 4, 3, 7], true },
            {
                "Example 2: Invalid Even-Odd Tree (odd values at level 1)",
                [5, 9, 3, 12, null, null, 8],
                false
            },
            {
                "Example 3: Invalid Even-Odd Tree (even values at even level)",
                [7, 10, 2, 12, 8],
                false
            },
            { "Single node (odd value at level 0)", [1], true },
            { "Single node (even value at level 0)", [2], false },
            { "Empty tree", [], true },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void IsEvenOddTree(string name, int?[] tree, bool want)
    {
        bool got = EvenOddTree.IsEvenOddTree(Shared.ToTree(tree));

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
