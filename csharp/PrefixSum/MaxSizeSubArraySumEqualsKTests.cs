namespace DsaPatterns.PrefixSum;

public class MaxSizeSubArraySumEqualsKTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [1, -1, 5, -2, 3], 3, 4 },
            { "Example 2", [-2, -1, 2, 1], 1, 2 },
            { "Example 3", [1, 2, 3], 6, 3 },
            { "Example 4", [1, 2, 3], 7, 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MaxSizeSubArraySumEqualsKTest(string name, int[] nums, int k, int want)
    {
        int got = MaxSizeSubArraySumEqualsK.Find(nums, k);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
