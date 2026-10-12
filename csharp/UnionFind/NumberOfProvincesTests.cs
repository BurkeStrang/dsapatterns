namespace DsaPatterns.UnionFind;

public class NumberOfProvincesTests
{
    public static TheoryData<string, int[][], int> Cases =>
        new()
        {
            { "Example 1", new int[][] { [1, 1, 0], [1, 1, 0], [0, 0, 1] }, 2 },
            { "Example 2", new int[][] { [1, 0, 0], [0, 1, 0], [0, 0, 1] }, 3 },
            { "Example 3", new int[][] { [1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 0], [1, 0, 0, 1] }, 2 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindProvinces(string name, int[][] isConnected, int want)
    {
        int got = NumberOfProvinces.FindProvinces(isConnected);
        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
