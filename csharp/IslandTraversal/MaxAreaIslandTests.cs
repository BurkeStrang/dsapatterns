namespace DsaPatterns.IslandTraversal;

public class MaxAreaIslandTests
{
    public static TheoryData<string, int[][], int> Cases =>
        new()
        {
            {
                "single island",
                [
                    [0, 1, 0, 0],
                    [1, 1, 0, 0],
                    [0, 0, 1, 1],
                    [0, 0, 1, 1],
                ],
                4
            },
            {
                "no island",
                [
                    [0, 0, 0],
                    [0, 0, 0],
                ],
                0
            },
            {
                "multiple islands",
                [
                    [1, 0, 0, 1],
                    [0, 1, 1, 0],
                    [0, 0, 0, 1],
                ],
                2
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MaxAreaOfIsland(string name, int[][] matrix, int want)
    {
        int got = MaxAreaIsland.MaxAreaOfIsland(Shared.CopyMatrix(matrix));

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
