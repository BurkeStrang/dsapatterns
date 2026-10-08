namespace DsaPatterns.CyclicalSort;

public class FindMinMissingPosNumTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [-3, 1, 5, 4, 2], 3 },
            { "Example 2", [3, -2, 0, 1, 2], 4 },
            { "Example 3", [3, 2, 5, 1], 4 },
            { "Example 4", [33, 37, 5], 1 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMis(string name, int[] nums, int want)
    {
        int got = FindMinMissingPosNum.FindMis(nums);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
