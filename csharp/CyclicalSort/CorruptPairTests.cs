namespace DsaPatterns.CyclicalSort;

public class CorruptPairTests
{
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            { "Example 1", [3, 1, 2, 5, 2], [2, 4] },
            { "Example 2", [3, 1, 2, 3, 6, 4], [3, 5] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindCorrupt(string name, int[] nums, int[] want)
    {
        int[] got = [.. CorruptPair.FindCorrupt(nums)];

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
