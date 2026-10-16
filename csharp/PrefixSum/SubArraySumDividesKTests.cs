namespace DsaPatterns.PrefixSum;

public class SubArraySumDividesKTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [3, 1, 2, -2, 5, -1], 3, 7 },
            { "Example 2", [4, 5, 0, -2, -3, 1], 5, 7 },
            { "Example 3", [-1, 2, 9], 2, 2 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SubArraySumDividesKTest(string name, int[] nums, int k, int want)
    {
        int got = SubArraySumDividesK.Count(nums, k);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
