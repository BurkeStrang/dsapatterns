namespace DsaPatterns.TreeBfs;

public class LevelAveragesTests
{
    // trees are given in level order, with null for a missing child
    public static TheoryData<string, int?[], double[]> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3, 4, 5, 6, 7], [1, 2.5, 5.5] },
            { "Example 2", [12, 7, 1, null, 9, 10, 5], [12, 4, 8] },
            { "Empty tree", [], [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void LevelAverage(string name, int?[] tree, double[] want)
    {
        List<double> got = LevelAverages.LevelAverage(Shared.ToTree(tree));

        Assert.True(
            Shared.EqualDoubles(got, want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
