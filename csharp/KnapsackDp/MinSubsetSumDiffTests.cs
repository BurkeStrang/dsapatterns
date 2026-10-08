namespace DsaPatterns.KnapsackDp;

public class MinSubsetSumDiffTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3, 9], 3 },
            { "Example 2", [1, 2, 7, 1, 5], 0 },
            { "Example 3", [1, 3, 100, 4], 92 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CanPartitionMin(string name, int[] num, int want)
    {
        int got = MinSubsetSumDiff.CanPartitionMin(num);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
