namespace DsaPatterns.CyclicalSort;

public class FindDupsTests
{
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            { "Example 1", [3, 4, 4, 5, 5], [5, 4] },
            { "Example 2", [5, 4, 7, 2, 3, 5, 3], [3, 5] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindDuplicates(string name, int[] nums, int[] want)
    {
        int[] got = [.. FindDups.FindDuplicates(nums)];

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
