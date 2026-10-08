namespace DsaPatterns.TopKElements;

public class ScheduelingTaskTests
{
    public static TheoryData<string, string[], int, int> Cases =>
        new() { { "Example 1", ["a", "a", "a", "b", "c", "c"], 2, 7 } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void ScheduleTasks(string name, string[] tasks, int k, int want)
    {
        int got = ScheduelingTask.ScheduleTasks(tasks, k);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
