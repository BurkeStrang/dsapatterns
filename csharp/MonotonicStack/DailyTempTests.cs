namespace DsaPatterns.MonotonicStack;

public class DailyTempTests
{
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            {
                "Example 1",
                [70, 73, 75, 71, 69, 72, 76, 73],
                [1, 1, 4, 2, 1, 1, 0, 0]
            },
            { "Example 2", [73, 72, 71, 70], [0, 0, 0, 0] },
            { "Example 3", [70, 71, 72, 73], [1, 1, 1, 0] },
            { "All same", [60, 60, 60], [0, 0, 0] },
            { "Single element", [80], [0] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void DailyTemperatures(string name, int[] temperatures, int[] want)
    {
        int[] got = DailyTemp.DailyTemperatures(temperatures);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
