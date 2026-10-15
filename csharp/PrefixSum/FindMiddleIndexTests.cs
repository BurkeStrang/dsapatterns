namespace DsaPatterns.PrefixSum;

public class FindMiddleIndexTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [1, 7, 3, 6, 5, 6], 3 },
            { "Example 2", [2, 1, -1], 0 },
            { "Example 3", [2, 3, 5, 5, 3, 2], -1 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMiddleIndexTest(string name, int[] nums, int want)
    {
        int got = FindMiddleIndex.Get(nums);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
