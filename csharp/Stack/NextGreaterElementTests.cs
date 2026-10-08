namespace DsaPatterns.Stack;

public class NextGreaterElementTests
{
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            { "Example 1", [4, 5, 2, 25], [5, 25, 25, -1] },
            { "Example 2", [13, 7, 6, 12], [-1, 12, 12, -1] },
            { "Example 3", [1, 2, 3, 4, 5], [2, 3, 4, 5, -1] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void NextLargerElement(string name, int[] arr, int[] want)
    {
        int[] got = NextGreaterElement.NextLargerElement(arr);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
