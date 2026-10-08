namespace DsaPatterns.CyclicalSort;

public class FindMissingNumTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [4, 0, 3, 1], 2 },
            { "Example 2", [8, 3, 5, 2, 4, 6, 0, 1], 7 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMissingNumber(string name, int[] nums, int want)
    {
        int got = FindMissingNum.FindMissingNumber(nums);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
