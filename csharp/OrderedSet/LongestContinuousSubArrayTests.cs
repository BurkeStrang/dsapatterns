namespace DsaPatterns.OrderedSet;

public class LongestContinuousSubArrayTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [10, 1, 2, 4, 7], 5, 3 },
            { "Example 2", [4, 8, 5, 1, 7, 9], 3, 2 },
            { "Example 3", [3, 3, 3, 3, 3], 0, 5 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindLongestContinuousSubArray(string name, int[] nums, int limit, int want)
    {
        int got = LongestContinuousSubArray.Find(nums, limit);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
