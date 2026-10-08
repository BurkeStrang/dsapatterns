namespace DsaPatterns.MergeIntervals;

public class ConflictingAppointmentsTests
{
    public static TheoryData<string, int[][], bool> Cases =>
        new()
        {
            {
                "Example 1: overlapping intervals",
                [
                    [1, 4],
                    [2, 5],
                    [7, 9],
                ],
                false
            },
            {
                "Example 2: non-overlapping intervals",
                [
                    [6, 7],
                    [2, 4],
                    [13, 14],
                    [8, 12],
                    [45, 47],
                ],
                true
            },
            {
                "Example 3: overlapping intervals",
                [
                    [4, 5],
                    [2, 3],
                    [3, 6],
                ],
                false
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CanAttendAllAppointments(
        string name,
        int[][] intervals,
        bool want
    )
    {
        bool got = ConflictingAppointments.CanAttendAllAppointments(
            Shared.ToIntervals(intervals)
        );

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
