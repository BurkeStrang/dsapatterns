namespace DsaPatterns.TopKElements;

public class TopKNumbersTests
{
    public static TheoryData<string, int[], int, int[]> Cases =>
        new()
        {
            { "Example 1", [3, 1, 5, 12, 2, 11], 3, [5, 12, 11] },
            { "Example 2", [5, 12, 11, -1, 12], 3, [12, 11, 12] },
            { "All negative", [-3, -1, -5, -12, -2, -11], 3, [-1, -2, -3] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindKLargestNumbers(string name, int[] nums, int k, int[] want)
    {
        int[] got = TopKNumbers.FindKLargestNumbers(nums, k);

        // the numbers can come back in any order
        Assert.True(
            got.Order().SequenceEqual(want.Order()),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
