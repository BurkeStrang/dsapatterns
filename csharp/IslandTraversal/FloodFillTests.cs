namespace DsaPatterns.IslandTraversal;

public class FloodFillTests
{
    public static TheoryData<string, int[][], int, int, int, int[][]> Cases =>
        new()
        {
            {
                "basic flood fill",
                [
                    [1, 1, 1],
                    [1, 1, 0],
                    [1, 0, 1],
                ],
                1,
                1,
                2,
                [
                    [2, 2, 2],
                    [2, 2, 0],
                    [2, 0, 1],
                ]
            },
            {
                "starting point already new color",
                [
                    [0, 0],
                    [0, 1],
                ],
                1,
                1,
                1,
                [
                    [0, 0],
                    [0, 1],
                ]
            },
            {
                "no fill when starting outside bounds",
                [
                    [1, 1],
                    [1, 1],
                ],
                3, // outside grid
                0,
                5,
                [
                    [1, 1],
                    [1, 1],
                ]
            },
            {
                "single cell matrix",
                [
                    [1],
                ],
                0,
                0,
                9,
                [
                    [9],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Fill(
        string name,
        int[][] matrix,
        int x,
        int y,
        int newColor,
        int[][] want
    )
    {
        // Copy matrix to avoid modifying shared test cases
        int[][] input = Shared.CopyMatrix(matrix);

        int[][] got = FloodFill.Fill(input, x, y, newColor);

        Assert.True(
            Shared.Format2D(got) == Shared.Format2D(want),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }
}
