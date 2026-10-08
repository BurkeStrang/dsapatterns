namespace DsaPatterns.FastAndSlowPointers;

public class FindMiddleTests
{
    // want is the value of the middle node, or null for an empty list
    public static TheoryData<string, int[], int?> Cases =>
        new()
        {
            { "odd length list", [1, 2, 3, 4, 5], 3 },
            { "even length list", [1, 2, 3, 4], 3 },
            { "single node", [1], 1 },
            { "two nodes", [1, 2], 2 },
            { "nil list", [], null },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Middle(string name, int[] vals, int? want)
    {
        int? got = FindMiddle.Middle(Shared.ToList(vals))?.Val;

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
