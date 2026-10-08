namespace DsaPatterns.IslandTraversal;

public class NumIslandsTests
{
    public static TheoryData<string, int[][], int> Cases =>
        new()
        {
            {
                "single island",
                [
                    [1, 1, 0, 0],
                    [1, 1, 0, 0],
                    [0, 0, 1, 0],
                    [0, 0, 0, 1],
                ],
                3
            },
            {
                "no islands",
                [
                    [0, 0, 0],
                    [0, 0, 0],
                ],
                0
            },
            {
                "all land",
                [
                    [1, 1],
                    [1, 1],
                ],
                1
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CountIslands(string name, int[][] matrix, int want)
    {
        int got = NumIslands.CountIslands(Shared.CopyMatrix(matrix));

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
