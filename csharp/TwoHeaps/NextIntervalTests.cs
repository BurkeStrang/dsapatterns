namespace DsaPatterns.TwoHeaps;

public class NextIntervalTests
{
    // intervals are given as [start, end] pairs
    public static TheoryData<string, int[][], int[]> Cases =>
        new()
        {
            {
                "basic non-overlapping",
                [
                    [2, 3],
                    [3, 4],
                    [5, 6],
                ],
                [1, 2, -1]
            },
            {
                "overlapping intervals",
                [
                    [3, 4],
                    [1, 5],
                    [4, 6],
                ],
                [2, -1, -1]
            },
            {
                "single interval",
                [
                    [1, 2],
                ],
                [-1]
            },
            {
                "self as next interval",
                [
                    [1, 1],
                    [3, 4],
                ],
                [0, -1]
            },
            {
                "no next interval for identical",
                [
                    [1, 2],
                    [1, 2],
                    [1, 2],
                ],
                [-1, -1, -1]
            },
            {
                "start equals end",
                [
                    [1, 2],
                    [2, 3],
                    [3, 4],
                ],
                [1, 2, -1]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindNextInterval(string name, int[][] intervals, int[] want)
    {
        Interval[] input = intervals
            .Select(pair => new Interval(pair[0], pair[1]))
            .ToArray();

        int[] got = NextInterval.FindNextInterval(input);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
