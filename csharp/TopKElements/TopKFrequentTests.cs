namespace DsaPatterns.TopKElements;

public class TopKFrequentTests
{
    // valid lists every number that is allowed to appear in the answer, since
    // numbers with the same frequency can be picked in any order
    public static TheoryData<string, int[], int, int[]> Cases =>
        new()
        {
            { "Example 1", [1, 3, 5, 12, 11, 12, 11], 2, [11, 12] },
            { "Example 2", [5, 12, 11, 3, 11], 2, [11, 5, 12, 3] },
            { "Example 3", [1, 1, 1, 3, 3, 3, 5, 5, 5, 12], 2, [1, 3, 5] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindTopKFrequentNumbers(
        string name,
        int[] nums,
        int k,
        int[] valid
    )
    {
        int[] got = TopKFrequent.FindTopKFrequentNumbers(nums, k);

        Assert.True(
            got.Length == k && got.All(valid.Contains),
            $"{name}: got {Shared.Format(got)}, "
                + $"want {k} of {Shared.Format(valid)}"
        );
    }
}
