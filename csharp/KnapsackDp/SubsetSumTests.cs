namespace DsaPatterns.KnapsackDp;

public class SubsetSumTests
{
    public static TheoryData<string, int[], int, bool> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3, 7], 6, true },
            { "Example 2", [1, 2, 7, 1, 5], 10, true },
            { "Example 3", [1, 3, 4, 8], 6, false },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CanPartitionSum(string name, int[] nums, int sum, bool want)
    {
        bool got = SubsetSum.CanPartitionSum(nums, sum);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
