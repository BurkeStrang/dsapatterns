namespace DsaPatterns.CyclicalSort;

public class FindAllMissingNumTests
{
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            { "Example 1", [2, 3, 1, 8, 2, 3, 5, 1], [4, 6, 7] },
            { "Example 2", [2, 4, 1, 2], [3] },
            { "Example 3", [2, 3, 2, 1], [4] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindNumbers(string name, int[] nums, int[] want)
    {
        int[] got = [.. FindAllMissingNum.FindNumbers(nums)];

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
