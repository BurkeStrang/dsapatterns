namespace DsaPatterns.MergeIntervals;

public class MergeIntervalsTests
{
    public static TheoryData<string, int[][], int[][]> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [1, 4],
                    [2, 5],
                    [7, 9],
                ],
                [
                    [1, 5],
                    [7, 9],
                ]
            },
            {
                "Example 2",
                [
                    [6, 7],
                    [2, 4],
                    [5, 9],
                ],
                [
                    [2, 4],
                    [5, 9],
                ]
            },
            {
                "Example 3",
                [
                    [1, 4],
                    [2, 6],
                    [3, 5],
                ],
                [
                    [1, 6],
                ]
            },
            {
                "No overlap",
                [
                    [1, 2],
                    [3, 4],
                    [5, 6],
                ],
                [
                    [1, 2],
                    [3, 4],
                    [5, 6],
                ]
            },
            {
                "Single interval",
                [
                    [1, 10],
                ],
                [
                    [1, 10],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Merge(string name, int[][] intervals, int[][] want)
    {
        List<Interval> got = MergeIntervals.Merge(
            Shared.ToIntervals(intervals)
        );

        Assert.True(
            got.SequenceEqual(Shared.ToIntervals(want)),
            $"{name}: got {Shared.Format(got)}"
        );
    }
}
