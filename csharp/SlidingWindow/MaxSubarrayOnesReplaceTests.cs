namespace DsaPatterns.SlidingWindow;

public class MaxSubarrayOnesReplaceTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], 2, 6 },
            { "Example 2", [0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], 3, 9 },
            { "Example 3", [1, 0, 0, 1, 1, 0, 1, 1], 2, 6 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MaxOnesLength(string name, int[] arr, int k, int want)
    {
        int got = MaxSubarrayOnesReplace.MaxOnesLength(arr, k);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
