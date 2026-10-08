namespace DsaPatterns.KnapsackDp;

public class CountOfSubsetSumTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [1, 1, 2, 3], 4, 3 },
            { "Example 2", [1, 2, 7, 1, 5], 9, 3 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CountSubsets(string name, int[] num, int sum, int want)
    {
        int got = CountOfSubsetSum.CountSubsets(num, sum);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
