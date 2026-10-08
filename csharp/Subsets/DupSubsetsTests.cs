namespace DsaPatterns.Subsets;

public class DupSubsetsTests
{
    public static TheoryData<string, int[], int[][]> Cases =>
        new()
        {
            {
                "example test case 1",
                [1, 3, 3],
                [
                    [],
                    [1],
                    [3],
                    [1, 3],
                    [3, 3],
                    [1, 3, 3],
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
    public void FindDupSubsets(string name, int[] nums, int[][] want)
    {
        List<List<int>> got = DupSubsets.FindDupSubsets(nums);

        string gotText = Shared.Format2D(Shared.SortRows(got));
        string wantText = Shared.Format2D(Shared.SortRows(want));
        Assert.True(
            gotText == wantText,
            $"{name}: got {gotText}, want {wantText}"
        );
    }
}
