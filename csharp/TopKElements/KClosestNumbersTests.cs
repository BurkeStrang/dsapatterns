namespace DsaPatterns.TopKElements;

public class KClosestNumbersTests
{
    public static TheoryData<string, int[], int, int, int[]> Cases =>
        new()
        {
            { "Example 1", [5, 6, 7, 8, 9], 3, 7, [6, 7, 8] },
            { "Example 2", [2, 4, 5, 6, 9], 3, 6, [4, 5, 6] },
            { "Example 3", [2, 4, 5, 6, 9], 3, 10, [5, 6, 9] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindClosestElements(
        string name,
        int[] arr,
        int k,
        int x,
        int[] want
    )
    {
        List<int> got = KClosestNumbers.FindClosestElements(arr, k, x);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
