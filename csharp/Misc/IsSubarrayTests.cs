namespace DsaPatterns.Misc;

public class IsSubarrayTests
{
    public static TheoryData<string, int[], int[], bool> Cases =>
        new() { { "Example 1", [1, 2, 3], [2, 3], true } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Contains(string name, int[] nums, int[] sub, bool want)
    {
        bool got = IsSubarray.Contains(nums, sub);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
