namespace DsaPatterns.MergeIntervals;

public class IntersectionTests
{
    public static TheoryData<string, int[][], int[][], int[][]> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [1, 3],
                    [5, 6],
                    [7, 9],
                ],
                [
                    [2, 3],
                    [5, 7],
                ],
                [
                    [2, 3],
                    [5, 6],
                    [7, 7],
                ]
            },
            {
                "Example 2",
                [
                    [1, 3],
                    [5, 7],
                    [9, 12],
                ],
                [
                    [5, 10],
                ],
                [
                    [5, 7],
                    [9, 10],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void IntersectingIntervals(
        string name,
        int[][] arr1,
        int[][] arr2,
        int[][] want
    )
    {
        List<Interval> got = Intersection.IntersectingIntervals(
            Shared.ToIntervals(arr1),
            Shared.ToIntervals(arr2)
        );

        Assert.True(
            got.SequenceEqual(Shared.ToIntervals(want)),
            $"{name}: got {Shared.Format(got)}"
        );
    }
}
