namespace DsaPatterns.CyclicalSort;

public class FindDupTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [1, 4, 4, 3, 2], 4 },
            { "Example 2", [2, 1, 3, 3, 5, 4], 3 },
            { "Example 3", [2, 4, 1, 4, 4], 4 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindDuplicate(string name, int[] nums, int want)
    {
        int got = FindDup.FindDuplicate(nums);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
