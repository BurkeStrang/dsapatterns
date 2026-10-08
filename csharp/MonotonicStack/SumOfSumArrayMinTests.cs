namespace DsaPatterns.MonotonicStack;

public class SumOfSumArrayMinTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [3, 1, 2, 4, 5], 30 },
            { "Example 2", [2, 6, 5, 4], 36 },
            { "Example 3", [7, 3, 8], 27 },
            { "Single element", [5], 5 },
            { "All same elements", [2, 2, 2], 12 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SumSubarrayMins(string name, int[] arr, int want)
    {
        int got = SumOfSumArrayMin.SumSubarrayMins(arr);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
