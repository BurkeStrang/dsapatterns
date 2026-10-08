namespace DsaPatterns.Backtracking;

public class FactorCombinationsTests
{
    public static TheoryData<string, int, int[][]> Cases =>
        new()
        {
            {
                "Example 1",
                8,
                [
                    [2, 2, 2],
                    [2, 4],
                ]
            },
            {
                "Example 2",
                20,
                [
                    [2, 2, 5],
                    [2, 10],
                    [4, 5],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void GetFactors(string name, int n, int[][] want)
    {
        List<List<int>> got = FactorCombinations.GetFactors(n);

        // the combinations can come back in any order
        string gotText = Shared.Format2D(Shared.SortRows(got));
        string wantText = Shared.Format2D(Shared.SortRows(want));
        Assert.True(
            gotText == wantText,
            $"{name}: got {gotText}, want {wantText}"
        );
    }
}
