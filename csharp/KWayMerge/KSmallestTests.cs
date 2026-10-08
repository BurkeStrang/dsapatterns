namespace DsaPatterns.KWayMerge;

public class KSmallestTests
{
    public static TheoryData<string, int[][], int, int> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [2, 6, 8],
                    [3, 6, 7],
                    [1, 3, 4],
                ],
                5,
                4
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindKthSmallest(string name, int[][] lists, int k, int want)
    {
        int got = KSmallest.FindKthSmallest(lists, k);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
