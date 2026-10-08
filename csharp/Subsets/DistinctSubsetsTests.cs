namespace DsaPatterns.Subsets;

public class DistinctSubsetsTests
{
    public static TheoryData<string, int[], int[][]> Cases =>
        new()
        {
            {
                "example test case 1",
                [1, 3],
                [
                    [],
                    [1],
                    [3],
                    [1, 3],
                ]
            },
            {
                "example test case 2",
                [1, 2, 3],
                [
                    [],
                    [1],
                    [2],
                    [3],
                    [1, 2],
                    [1, 3],
                    [2, 3],
                    [1, 2, 3],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindSubsets(string name, int[] nums, int[][] want)
    {
        List<List<int>> got = DistinctSubsets.FindSubsets(nums);

        string gotText = Shared.Format2D(Shared.SortRows(got));
        string wantText = Shared.Format2D(Shared.SortRows(want));
        Assert.True(
            gotText == wantText,
            $"{name}: got {gotText}, want {wantText}"
        );
    }
}
