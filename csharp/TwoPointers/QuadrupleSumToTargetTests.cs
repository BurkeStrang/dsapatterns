namespace DsaPatterns.TwoPointers;

public class QuadrupleSumToTargetTests
{
    public static TheoryData<int[], int, int[][]> Cases =>
        new()
        {
            {
                [4, 1, 2, -1, 1, -3],
                1,
                [
                    [-3, -1, 1, 4],
                    [-3, 1, 1, 2],
                ]
            },
            {
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
    public void SearchQuadruplets(int[] arr, int target, int[][] expected)
    {
        List<List<int>> result = QuadrupleSumToTarget.SearchQuadruplets(
            arr,
            target
        );

        Assert.Equal(Shared.SortRows(expected), Shared.SortRows(result));
    }
}
