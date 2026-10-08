namespace DsaPatterns.KWayMerge;

public class SmallestRangeTests
{
    public static TheoryData<string, int[][], int[]> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [1, 5, 8],
                    [4, 12],
                    [7, 8, 10],
                ],
                [4, 7]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindSmallestRange(string name, int[][] inputLists, int[] want)
    {
        int[] got = SmallestRange.FindSmallestRange(inputLists);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
