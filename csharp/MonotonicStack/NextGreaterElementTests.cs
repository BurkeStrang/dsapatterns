namespace DsaPatterns.MonotonicStack;

public class NextGreaterElementTests
{
    public static TheoryData<string, int[], int[], int[]> Cases =>
        new()
        {
            { "Example 1", [4, 2, 6], [6, 2, 4, 5, 3, 7], [5, 4, 7] },
            { "Example 2", [9, 7, 1], [1, 7, 9, 5, 4, 3], [-1, 9, 7] },
            { "Example 3", [5, 12, 3], [12, 3, 5, 4, 10, 15], [10, 15, 5] },
            { "No greater element", [8], [8, 7, 6], [-1] },
            { "All increasing", [1, 2, 3], [1, 2, 3, 4], [2, 3, 4] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindNextGreaterElement(
        string name,
        int[] nums1,
        int[] nums2,
        int[] want
    )
    {
        int[] got = NextGreaterElement.FindNextGreaterElement(nums1, nums2);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
