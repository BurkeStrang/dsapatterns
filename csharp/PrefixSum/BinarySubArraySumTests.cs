namespace DsaPatterns.PrefixSum;

public class BinarySubArraySumTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [1, 0, 1, 0, 1], 2, 4 },
            { "Example 2", [0, 0, 0, 0, 0], 0, 15 },
            { "Example 3", [1, 1, 1, 1], 3, 2 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CountSubarraysWithSumTest(string name, int[] nums, int targetSum, int want)
    {
        int got = BinarySubArraySum.Find(nums, targetSum);

        Assert.True(got == want,
                $"{name}: got {got}, want {want}");
    }
}
