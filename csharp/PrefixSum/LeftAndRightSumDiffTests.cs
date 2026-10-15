namespace DsaPatterns.PrefixSum;

public class LeftAndRightSumDiffTests
{
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            { "Example 1", [2, 5, 1, 6, 1], [13, 6, 0, 7, 14] },
            { "Example 2", [3, 3, 3], [6, 0, 6] },
            { "Example 3", [1, 2, 3, 4, 5], [14, 11, 6, 1, 10] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void LeftRightSumDiffTest(string name, int[] nums, int[] want)
    {
        int[] got = LeftAndRightSumDiff.Find(nums);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got [{string.Join(", ", got)}], want [{string.Join(", ", want)}]"
        );
    }
}
