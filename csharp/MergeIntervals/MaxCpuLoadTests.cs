namespace DsaPatterns.MergeIntervals;

public class MaxCpuLoadTests
{
    // each job is [start, end, cpuLoad]
    public static TheoryData<string, int[][], int> Cases =>
        new()
        {
            {
                "Example 1: overlapping jobs",
                [
                    [1, 4, 3],
                    [2, 5, 4],
                    [7, 9, 6],
                ],
                7
            },
            {
                "Example 2: non-overlapping jobs",
                [
                    [6, 7, 10],
                    [2, 4, 11],
                    [8, 12, 15],
                ],
                15
            },
            {
                "Example 3: all overlap",
                [
                    [1, 4, 2],
                    [2, 4, 1],
                    [3, 6, 5],
                ],
                8
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMaxCpuLoad(string name, int[][] jobs, int want)
    {
        Job[] input = jobs.Select(j => new Job(j[0], j[1], j[2])).ToArray();

        int got = MaxCpuLoad.FindMaxCpuLoad(input);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
