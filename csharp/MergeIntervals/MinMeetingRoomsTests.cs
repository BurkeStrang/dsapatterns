namespace DsaPatterns.MergeIntervals;

public class MinMeetingRoomsTests
{
    public static TheoryData<string, int[][], int> Cases =>
        new()
        {
            {
                "Example 1: overlapping meetings",
                [
                    [1, 4],
                    [2, 5],
                    [7, 9],
                ],
                2
            },
            {
                "Example 2: non-overlapping meetings",
                [
                    [6, 7],
                    [2, 4],
                    [8, 12],
                ],
                1
            },
            {
                "Example 3: overlapping meetings",
                [
                    [1, 4],
                    [2, 3],
                    [3, 6],
                ],
                2
            },
            {
                "Example 4: complex overlaps",
                [
                    [4, 5],
                    [2, 3],
                    [2, 4],
                    [3, 5],
                ],
                2
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMinimumMeetingRooms(string name, int[][] meetings, int want)
    {
        Meeting[] input = meetings
            .Select(m => new Meeting(m[0], m[1]))
            .ToArray();

        int got = MinMeetingRooms.FindMinimumMeetingRooms(input);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
