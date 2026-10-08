namespace DsaPatterns.SlidingWindow;

public class MaximumSubTests
{
    public static TheoryData<string, int, int[], int> Cases =>
        new()
        {
            { "basic case", 3, [2, 1, 5, 1, 3, 2], 9 },
            { "single element window", 1, [4, 2, 7, 1], 7 },
            { "window equals array length", 4, [1, 2, 3, 4], 10 },
            { "empty array", 3, [], 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMaxSumSubArray(string name, int k, int[] arr, int want)
    {
        int got = MaximumSub.FindMaxSumSubArray(k, arr);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
