namespace DsaPatterns.KWayMerge;

public class KPairsLargestSumTests
{
    public static TheoryData<string, int[], int[], int, int[][]> Cases =>
        new()
        {
            {
                "Example 1",
                [9, 8, 2],
                [6, 3, 1],
                3,
                [
                    [9, 3],
                    [8, 6],
                    [9, 6],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindKLargestPairs(
        string name,
        int[] nums1,
        int[] nums2,
        int k,
        int[][] want
    )
    {
        List<int[]> got = KPairsLargestSum.FindKLargestPairs(nums1, nums2, k);

        Assert.True(
            Shared.Format2D(got) == Shared.Format2D(want),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }
}
