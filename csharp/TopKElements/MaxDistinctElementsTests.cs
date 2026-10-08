namespace DsaPatterns.TopKElements;

public class MaxDistinctElementsTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [7, 3, 5, 8, 5, 3, 3], 2, 3 },
            { "Example 2", [3, 5, 12, 11, 12], 3, 2 },
            { "Example 3", [1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5], 2, 3 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMaximumDistinctElements(
        string name,
        int[] nums,
        int k,
        int want
    )
    {
        int got = MaxDistinctElements.FindMaximumDistinctElements(nums, k);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
