namespace DsaPatterns.SlidingWindow;

public class SubsLessThanTargetTests
{
    public static TheoryData<string, int[], int, int[][]> Cases =>
        new()
        {
            {
                "Example 1",
                [2, 5, 3, 10],
                30,
                [
                    [2],
                    [2, 5],
                    [5],
                    [5, 3],
                    [3],
                    [10],
                ]
            },
            {
                "Example 2",
                [8, 2, 6, 5],
                50,
                [
                    [8],
                    [8, 2],
                    [2],
                    [2, 6],
                    [6],
                    [6, 5],
                    [5],
                ]
            },
            { "Target 0", [10, 5, 2, 6], 0, [] },
            {
                "Single element < target",
                [1],
                2,
                [
                    [1],
                ]
            },
            { "Single element >= target", [5], 5, [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindSubarrays(string name, int[] arr, int target, int[][] want)
    {
        List<List<int>> got = SubsLessThanTarget.FindSubarrays(arr, target);

        Assert.True(
            Shared.EqualUnordered2D(got, want),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }
}
