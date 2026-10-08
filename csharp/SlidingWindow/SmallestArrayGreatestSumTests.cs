namespace DsaPatterns.SlidingWindow;

public class SmallestArrayGreatestSumTests
{
    public static TheoryData<string, int, int[], int> Cases =>
        new()
        {
            { "Example 1", 7, [2, 1, 5, 2, 3, 2], 2 },
            { "Example 2", 7, [2, 1, 5, 2, 8], 1 },
            { "Example 3", 8, [3, 4, 1, 1, 6], 3 },
            { "No subarray meets S", 20, [1, 2, 3, 4], 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMinSubArray(string name, int s, int[] arr, int want)
    {
        int got = SmallestArrayGreatestSum.FindMinSubArray(s, arr);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
