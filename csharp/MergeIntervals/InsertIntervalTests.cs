namespace DsaPatterns.MergeIntervals;

public class InsertIntervalTests
{
    public static TheoryData<string, int[][], int[], int[][]> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [1, 3],
                    [5, 7],
                    [8, 12],
                ],
                [4, 6],
                [
                    [1, 3],
                    [4, 7],
                    [8, 12],
                ]
            },
            {
                "Example 2",
                [
                    [1, 3],
                    [5, 7],
                    [8, 12],
                ],
                [4, 10],
                [
                    [1, 3],
                    [4, 12],
                ]
            },
            {
                "Example 3",
                [
                    [2, 3],
                    [5, 7],
                ],
                [1, 4],
                [
                    [1, 4],
                    [5, 7],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Insert(
        string name,
        int[][] intervals,
        int[] newInterval,
        int[][] want
    )
    {
        List<Interval> got = InsertInterval.Insert(
            Shared.ToIntervals(intervals),
            new Interval(newInterval[0], newInterval[1])
        );

        Assert.True(
            got.SequenceEqual(Shared.ToIntervals(want)),
            $"{name}: got {Shared.Format(got)}"
        );
    }
}
