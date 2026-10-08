namespace DsaPatterns.FibNum;

public class HouseTheifTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [2, 5, 1, 3, 6, 2, 4], 15 },
            { "Example 2", [2, 10, 14, 8, 1], 18 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMaxSteal(string name, int[] wealth, int want)
    {
        int got = HouseTheif.FindMaxSteal(wealth);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
