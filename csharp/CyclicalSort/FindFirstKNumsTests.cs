namespace DsaPatterns.CyclicalSort;

public class FindFirstKNumsTests
{
    public static TheoryData<string, int[], int, int[]> Cases =>
        new()
        {
            { "Example 1", [3, -1, 4, 5, 5], 3, [1, 2, 6] },
            { "Example 2", [2, 3, 4], 3, [1, 5, 6] },
            { "Example 3", [-2, -3, 4], 2, [1, 2] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindFirstK(string name, int[] nums, int k, int[] want)
    {
        List<int> got = FindFirstKNums.FindFirstK(nums, k);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
