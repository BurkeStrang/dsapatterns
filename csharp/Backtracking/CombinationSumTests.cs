namespace DsaPatterns.Backtracking;

public class CombinationSumTests
{
    public static TheoryData<string, int[], int, int[][]> Cases =>
        new()
        {
            {
                "test1",
                [2, 3, 6, 7],
                7,
                [
                    [2, 2, 3],
                    [7],
                ]
            },
            {
                "test2",
                [2, 4, 6, 8],
                10,
                [
                    [2, 2, 2, 2, 2],
                    [2, 2, 2, 4],
                    [2, 2, 6],
                    [2, 4, 4],
                    [2, 8],
                    [4, 6],
                ]
            },
            { "test3", [2], 1, [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindCombinations(
        string name,
        int[] candidates,
        int target,
        int[][] want
    )
    {
        List<List<int>> got = CombinationSum.FindCombinations(
            candidates,
            target
        );

        Assert.True(
            Shared.Format2D(got) == Shared.Format2D(want),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }
}
