namespace DsaPatterns.IslandTraversal;

public class IslandPerimeterTests
{
    public static TheoryData<string, int[][], int> Cases =>
        new()
        {
            {
                "simple square island",
                [
                    [0, 1, 0],
                    [1, 1, 1],
                    [0, 1, 0],
                ],
                // shape is a plus sign → perimeter = 12
                12
            },
            {
                "single land cell",
                [
                    [1],
                ],
                4
            },
            // ends (3 sides + 3 sides) + middle (2 + 2)
            {
                "single row island",
                [
                    [1, 1, 1, 1],
                ],
                10
            },
            {
                "one big solid block",
                [
                    [1, 1],
                    [1, 1],
                ],
                // 2x2 block perimeter = 8
                8
            },
            {
                "L-shaped island",
                [
                    [1, 0],
                    [1, 1],
                ],
                // Shape:
                // 1 .
                // 1 1
                // Perimeter = 8
                8
            },
            {
                "island touching border",
                [
                    [1, 1, 0],
                    [1, 0, 0],
                    [1, 1, 1],
                ],
                // Count exposed edges manually → perimeter = 14
                14
            },
            {
                "island with a hole inside",
                [
                    [1, 1, 1],
                    [1, 0, 1],
                    [1, 1, 1],
                ],
                // A hollow square → perimeter counts both outer and inner edges
                // outer = 12, inner hole = 4 → total = 16
                16
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindIslandPerimeter(string name, int[][] matrix, int want)
    {
        int got = IslandPerimeter.FindIslandPerimeter(
            Shared.CopyMatrix(matrix)
        );

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
