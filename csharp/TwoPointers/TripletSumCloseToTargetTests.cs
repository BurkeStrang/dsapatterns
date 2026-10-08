namespace DsaPatterns.TwoPointers;

public class TripletSumCloseToTargetTests
{
    public static TheoryData<int[], int, int> Cases =>
        new()
        {
            { [-1, 0, 2, 3], 3, 2 },
            { [-3, -1, 1, 2], 1, 0 },
            { [1, 0, 1, 1], 100, 3 },
            { [0, 0, 1, 1, 2, 6], 5, 4 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SearchTriplet(int[] arr, int target, int expected)
    {
        int got = TripletSumCloseToTarget.SearchTriplet(arr, target);

        Assert.Equal(expected, got);
    }
}
