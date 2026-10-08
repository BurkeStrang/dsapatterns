namespace DsaPatterns.BitwiseXor;

public class TwoSingleNumbersTests
{
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            { "Example 1", [1, 4, 2, 1, 3, 5, 6, 2, 3, 5], [4, 6] },
            { "Example 2", [2, 1, 3, 2], [1, 3] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindSingleNumbers(string name, int[] nums, int[] want)
    {
        int[] got = TwoSingleNumbers.FindSingleNumbers(nums);

        Assert.True(
            Shared.EqualUnordered(got, want),
            $"{name}: got [{string.Join(", ", got)}], "
                + $"want [{string.Join(", ", want)}]"
        );
    }
}
