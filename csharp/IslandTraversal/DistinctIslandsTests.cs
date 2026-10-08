namespace DsaPatterns.IslandTraversal;

public class DistinctIslandsTests
{
    public static TheoryData<string, int[][], int> Cases =>
        new()
        {
            {
                "two distinct islands",
                [
                    [1, 1, 0, 0, 0],
                    [1, 0, 0, 1, 1],
                    [0, 0, 0, 1, 1],
                ],
                2
            },
            {
                "all islands same shape",
                [
                    [1, 0, 1, 0],
                    [1, 0, 1, 0],
                ],
                1
            },
            {
                "no islands",
                [
                    [0, 0],
                    [0, 0],
                ],
                0
            },
            {
                "single island",
                [
                    [1, 1],
                    [1, 1],
                ],
                1
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindDistinctIslandsDfs(string name, int[][] matrix, int want)
    {
        int got = DistinctIslands.FindDistinctIslandsDfs(
            Shared.CopyMatrix(matrix)
        );

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
