namespace DsaPatterns.KWayMerge;

public class KSmallestSortedMatrixTests
{
    public static TheoryData<string, int[][], int, int> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [2, 6, 8],
                    [3, 7, 10],
                    [5, 7, 8],
                ],
                5,
                7
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindKthSmallestPoint(
        string name,
        int[][] matrix,
        int k,
        int want
    )
    {
        int got = KSmallestSortedMatrix.FindKthSmallestPoint(matrix, k);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
