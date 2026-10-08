namespace DsaPatterns.FibNum;

public class MinJumpsTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [2, 1, 1, 1, 4], 3 },
            { "Example 2", [1, 1, 3, 6, 9, 3, 0, 1, 3], 4 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CountMinJumps(string name, int[] jumps, int want)
    {
        int got = MinJumps.CountMinJumps(jumps);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
