namespace DsaPatterns.TreeDfs;

public class PathWithSequenceTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int[], bool> Cases =>
        new()
        {
            {
                "Example 1: Path exists",
                [1, 7, 9, null, null, 2, 9],
                [1, 9, 9],
                true
            },
            {
                "Example 2: Path does not exist",
                [1, 0, 1, 1, 6, null, 5],
                [1, 0, 7],
                false
            },
            { "Example 3: Empty sequence", [1, 2], [], false },
            { "Example 4: Empty tree", [], [1], false },
            { "Example 5: Single node match", [5], [5], true },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindPath(string name, int?[] tree, int[] sequence, bool want)
    {
        bool got = PathWithSequence.FindPath(Shared.ToTree(tree), sequence);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
