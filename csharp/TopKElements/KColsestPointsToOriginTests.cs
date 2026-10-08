namespace DsaPatterns.TopKElements;

public class KColsestPointsToOriginTests
{
    // points are given as [x, y] pairs
    public static TheoryData<string, int[][], int, int[][]> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [1, 2],
                    [1, 3],
                ],
                1,
                [
                    [1, 2],
                ]
            },
            {
                "Example 2",
                [
                    [1, 3],
                    [3, 4],
                    [2, -1],
                ],
                2,
                [
                    [1, 3],
                    [2, -1],
                ]
            },
            {
                "Example 3",
                [
                    [1, 2],
                    [3, 4],
                    [1, -1],
                ],
                2,
                [
                    [1, -1],
                    [1, 2],
                ]
            },
            {
                "Example 4",
                [
                    [3, 3],
                    [5, -1],
                    [-2, 4],
                ],
                2,
                [
                    [3, 3],
                    [-2, 4],
                ]
            },
            {
                "All points are the same",
                [
                    [1, 1],
                    [1, 1],
                    [1, 1],
                ],
                2,
                [
                    [1, 1],
                    [1, 1],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindClosestPoints(
        string name,
        int[][] points,
        int k,
        int[][] want
    )
    {
        Point[] got = KColsestPointsToOrigin.FindClosestPoints(
            ToPoints(points),
            k
        );

        // the points can come back in any order
        IEnumerable<string> gotPoints = got.Select(p => $"({p.X},{p.Y})");
        IEnumerable<string> wantPoints = ToPoints(want)
            .Select(p => $"({p.X},{p.Y})");
        Assert.True(
            gotPoints.Order().SequenceEqual(wantPoints.Order()),
            $"{name}: got {Shared.Format(gotPoints)}, "
                + $"want {Shared.Format(wantPoints)}"
        );
    }

    private static Point[] ToPoints(int[][] pairs)
    {
        return pairs.Select(pair => new Point(pair[0], pair[1])).ToArray();
    }
}
