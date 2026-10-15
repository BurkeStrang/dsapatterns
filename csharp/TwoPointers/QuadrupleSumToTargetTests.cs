namespace DsaPatterns.TwoPointers;

public class QuadrupleSumToTargetTests
{
    public static TheoryData<string, int[], int, int[][]> Cases =>
        new()
        {
            {
                "Example 1",
                [4, 1, 2, -1, 1, -3],
                1,
                [
                    [-3, -1, 1, 4],
                    [-3, 1, 1, 2],
                ]
            },
            {
                "Example 2",
                [2, 0, -1, 1, -2, 2],
                2,
                [
                    [-2, 0, 2, 2],
                    [-1, 0, 1, 2],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SearchQuadruplets(string name, int[] arr, int target, int[][] want)
    {
        List<List<int>> got = QuadrupleSumToTarget.SearchQuadruplets(arr, target);

        Assert.True(
            Shared.Format2D(got) == Shared.Format2D(want),
            $"{name}: got {Shared.Format2D(got)}, " + $"want {Shared.Format2D(want)}"
        );
    }
}
