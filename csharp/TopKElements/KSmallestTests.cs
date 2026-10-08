namespace DsaPatterns.TopKElements;

public class KSmallestTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [1, 5, 12, 2, 11, 5], 3, 5 },
            { "Example 2", [1, 5, 12, 2, 11, 5], 4, 5 },
            { "Example 3", [5, 12, 11, -1, 12], 3, 11 },
            { "Example 4", [1, 5, 12, 2, 11, 5], 1, 1 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindKthSmallestNumber(string name, int[] nums, int k, int want)
    {
        int got = KSmallest.FindKthSmallestNumber(nums, k);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
