namespace DsaPatterns.MergeIntervals;

public class EmployeeFreeTimeTests
{
    public static TheoryData<string, int[][][], int[][]> Cases =>
        new()
        {
            {
                "Example 1: two employees, one free interval",
                [
                    [
                        [1, 3],
                        [5, 6],
                    ],
                    [
                        [2, 3],
                        [6, 8],
                    ],
                ],
                [
                    [3, 5],
                ]
            },
            {
                "Example 2: three employees, two free intervals",
                [
                    [
                        [1, 3],
                        [9, 12],
                    ],
                    [
                        [2, 4],
                    ],
                    [
                        [6, 8],
                    ],
                ],
                [
                    [4, 6],
                    [8, 9],
                ]
            },
            {
                "Example 3: three employees, one free interval",
                [
                    [
                        [1, 3],
                    ],
                    [
                        [2, 4],
                    ],
                    [
                        [3, 5],
                        [7, 9],
                    ],
                ],
                [
                    [5, 7],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindEmployeeFreeTime(
        string name,
        int[][][] schedule,
        int[][] want
    )
    {
        Interval[][] employees = schedule.Select(Shared.ToIntervals).ToArray();

        List<Interval> got = EmployeeFreeTime.FindEmployeeFreeTime(employees);

        Assert.True(
            got.SequenceEqual(Shared.ToIntervals(want)),
            $"{name}: got {Shared.Format(got)}"
        );
    }
}
