namespace DsaPatterns.TwoPointers;

public class TripletWithSmallerSumTests
{
    public static TheoryData<int[], int, int> Cases =>
        new()
        {
            { [-1, 0, 2, 3], 3, 2 },
            { [-1, 4, 2, 1, 3], 5, 4 },
            { [], 5, 0 },
            { [1, 2], 3, 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindTriplets(int[] arr, int target, int expected)
    {
        int result = TripletWithSmallerSum.FindTriplets(arr, target);

        Assert.Equal(expected, result);
    }
}
