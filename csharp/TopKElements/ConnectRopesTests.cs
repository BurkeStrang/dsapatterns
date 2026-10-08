namespace DsaPatterns.TopKElements;

public class ConnectRopesTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3, 4, 5], 33 },
            { "Example 2", [3, 4, 5, 6], 36 },
            { "Example 3", [1, 3, 11, 5, 2], 42 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MinimumCostToConnectRopes(
        string name,
        int[] ropeLengths,
        int want
    )
    {
        int got = ConnectRopes.MinimumCostToConnectRopes(ropeLengths);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
