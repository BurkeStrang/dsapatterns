namespace DsaPatterns.SlidingWindow;

public class SubsCountLessThanTargetTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [2, 5, 3, 10], 30, 6 },
            { "Example 2", [8, 2, 6, 5], 50, 7 },
            { "Example 3 (target 0)", [10, 5, 2, 6], 0, 0 },
            { "Single element < target", [1], 2, 1 },
            { "Single element >= target", [5], 5, 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindSubarrayCount(string name, int[] nums, int target, int want)
    {
        int got = SubsCountLessThanTarget.FindSubarrayCount(nums, target);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
