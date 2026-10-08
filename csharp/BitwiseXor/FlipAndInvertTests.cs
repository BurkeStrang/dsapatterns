namespace DsaPatterns.BitwiseXor;

public class FlipAndInvertTests
{
    public static TheoryData<string, int[][], int[][]> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [1, 0, 1],
                    [1, 1, 1],
                    [0, 1, 1],
                ],
                [
                    [0, 1, 0],
                    [0, 0, 0],
                    [0, 0, 1],
                ]
            },
            {
                "Example 2",
                [
                    [1, 1, 0, 0],
                    [1, 0, 0, 1],
                    [0, 1, 1, 1],
                    [1, 0, 1, 0],
                ],
                [
                    [1, 1, 0, 0],
                    [0, 1, 1, 0],
                    [0, 0, 0, 1],
                    [1, 0, 1, 0],
                ]
            },
            {
                "Single row",
                [
                    [1, 0, 0, 1],
                ],
                [
                    [0, 1, 1, 0],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FlipAndInvertImage(string name, int[][] arr, int[][] want)
    {
        int[][] got = FlipAndInvert.FlipAndInvertImage(arr);

        Assert.True(
            Shared.Equal2D(got, want),
            $"{name}: got {Shared.Format2D(got)}, want {Shared.Format2D(want)}"
        );
    }
}
