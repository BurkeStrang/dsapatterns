namespace DsaPatterns.OrderedSet;

public class MyCalendarTests
{
    public static TheoryData<string, int[][], bool[]> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [10, 20],
                    [15, 25],
                    [20, 30],
                ],
                [true, false, true]
            },
            {
                "Example 2",
                [
                    [5, 10],
                    [10, 15],
                    [5, 15],
                ],
                [true, true, false]
            },
            {
                "Example 3",
                [
                    [8, 13],
                    [13, 17],
                    [17, 20],
                ],
                [true, true, true]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Book(string name, int[][] nums, bool[] want)
    {
        List<bool> got = MyCalendar.Book(nums);

        Assert.True(
            want.SequenceEqual(got),
            $"{name} FAILED\n"
                + $"Want: [{string.Join(", ", want)}]\n"
                + $"Got:   [{string.Join(", ", got)}]"
        );
    }
}
