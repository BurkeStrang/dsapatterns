namespace DsaPatterns.TwoPointers;

public class PairWithTargetSumTests
{
    public static TheoryData<int[], int, int[]> Cases =>
        new()
        {
            { [1, 2, 3, 4, 6], 6, [1, 3] },
            { [2, 5, 9, 11], 11, [0, 2] },
            { [1, 2, 3, 4, 5], 10, [-1, -1] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Search(int[] arr, int target, int[] expected)
    {
        int[] result = PairWithTargetSum.Search(arr, target);

        Assert.Equal(expected, result);
    }
}
