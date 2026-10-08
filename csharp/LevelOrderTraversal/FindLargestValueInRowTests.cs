namespace DsaPatterns.LevelOrderTraversal;

public class FindLargestValueInRowTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], int[]> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3, 4, 5, null, 6], [1, 3, 6] },
            { "Example 2", [7, 4, 8, 2, 5, null, 9, null, 3], [7, 8, 9, 3] },
            { "Example 3", [10, 5], [10, 5] },
            { "Empty tree", [], [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void LargestValues(string name, int?[] tree, int[] want)
    {
        List<int> got = FindLargestValueInRow.LargestValues(
            Shared.ToTree(tree)
        );

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
