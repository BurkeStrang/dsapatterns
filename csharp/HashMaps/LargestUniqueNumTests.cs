namespace DsaPatterns.HashMaps;

public class LargestUniqueNumTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [5, 7, 3, 7, 5, 8], 8 },
            { "Example 2", [1, 2, 3, 2, 1, 4, 4], 3 },
            { "Example 3", [9, 9, 8, 8, 7, 7], -1 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void LargestUniqueNumber(string name, int[] a, int want)
    {
        int got = LargestUniqueNum.LargestUniqueNumber(a);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
