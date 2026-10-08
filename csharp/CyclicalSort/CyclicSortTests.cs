namespace DsaPatterns.CyclicalSort;

public class CyclicSortTests
{
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            { "Example 1", [3, 1, 5, 4, 2], [1, 2, 3, 4, 5] },
            { "Example 2", [2, 6, 4, 3, 1, 5], [1, 2, 3, 4, 5, 6] },
            { "Example 3", [1, 5, 6, 4, 3, 2], [1, 2, 3, 4, 5, 6] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Sort(string name, int[] nums, int[] want)
    {
        int[] got = [.. CyclicSort.Sort(nums)];

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
