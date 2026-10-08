namespace DsaPatterns.TwoPointers;

public class TripletesSumZeroTests
{
    public static TheoryData<int[], int[][]> Cases =>
        new()
        {
            {
                [-3, 0, 1, 2, -1, 1, -2],
                [
                    [-3, 1, 2],
                    [-2, 0, 2],
                    [-2, 1, 1],
                    [-1, 0, 1],
                ]
            },
            {
                [-5, 2, -1, -2, 3],
                [
                    [-5, 2, 3],
                    [-2, -1, 3],
                ]
            },
            { [1, 2, 3], [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SearchTriplets(int[] input, int[][] expected)
    {
        List<List<int>> got = TripletesSumZero.SearchTriplets(input);

        Assert.Equal(Shared.SortRows(expected), Shared.SortRows(got));
    }
}
