namespace DsaPatterns.IslandTraversal;

public class NumOfClosedTests
{
    public static TheoryData<string, int[][], int> Cases =>
        new()
        {
            {
                "one simple closed island",
                [
                    [1, 1, 1, 1, 1],
                    [1, 0, 0, 0, 1],
                    [1, 0, 1, 0, 1],
                    [1, 0, 0, 0, 1],
                    [1, 1, 1, 1, 1],
                ],
                1
            },
            {
                "two closed islands",
                [
                    [1, 1, 0, 1, 0, 0],
                    [1, 0, 1, 0, 0, 0],
                    [1, 0, 1, 0, 1, 0],
                    [1, 1, 0, 1, 0, 0],
                ],
                2
            },
            {
                "islands touching border are NOT closed",
                [
                    [0, 1, 1, 1],
                    [1, 0, 0, 1],
                    [1, 1, 0, 1],
                    [1, 1, 1, 1],
                ],
                // top-left 0 touches border → not closed
                // the connected 0s form one island, but it is open
                0
            },
            {
                "no land at all",
                [
                    [1, 1, 1],
                    [1, 1, 1],
                    [1, 1, 1],
                ],
                0
            },
            {
                "all land but touches border (so zero)",
                [
                    [0, 0, 0],
                    [0, 0, 0],
                    [0, 0, 0],
                ],
                0
            },
            {
                "complex inner islands but with border openings",
                [
                    [1, 1, 1, 1, 1, 1],
                    [1, 0, 0, 0, 0, 1],
                    [1, 0, 1, 0, 0, 1],
                    [0, 0, 0, 0, 1, 1], // leftmost 0 touches border
                    [1, 1, 1, 1, 1, 1],
                ],
                // open island on the left invalidates that region
                // right-side island is fully surrounded → 1 closed
                1
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CountClosedIslands(string name, int[][] matrix, int want)
    {
        int got = NumOfClosed.CountClosedIslands(Shared.CopyMatrix(matrix));

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
