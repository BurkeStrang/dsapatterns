namespace DsaPatterns.FibNum;

public class StaircaseTests
{
    public static TheoryData<string, int, int> Cases =>
        new() { { "Example 1", 3, 4 }, { "Example 2", 4, 7 } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CountWays(string name, int n, int want)
    {
        int got = Staircase.CountWays(n);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
