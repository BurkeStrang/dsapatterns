namespace DsaPatterns.TwoHeaps;

public class SlidingWindowMedianTests
{
    public static TheoryData<string, int[], int, double[]> Cases =>
        new()
        {
            { "k=2", [1, 2, -1, 3, 5], 2, [1.5, 0.5, 1.0, 4.0] },
            { "k=3", [1, 2, -1, 3, 5], 3, [1.0, 2.0, 3.0] },
            { "single element window", [4, 1, 3], 1, [4.0, 1.0, 3.0] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindSlidingWindowMedian(
        string name,
        int[] nums,
        int k,
        double[] expected
    )
    {
        SlidingWindowMedian solution = new();

        double[] result = solution.FindSlidingWindowMedian(nums, k);

        Assert.True(
            result.SequenceEqual(expected),
            $"{name}: got {Shared.Format(result)}, "
                + $"expected {Shared.Format(expected)}"
        );
    }
}
