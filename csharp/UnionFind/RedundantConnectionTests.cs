namespace DsaPatterns.UnionFind;

public class RedundantConnectionTests
{
    public static TheoryData<string, int[][], int[]> Cases =>
        new()
        {
            { "Example 1", [[1,2], [1,3], [3,4], [1,4], [1,5]], [ 1, 4 ] },
            { "Example 2", [[1,2], [2,3], [3,1], [3,4]], [3,1] },
            { "Example 3", [[1,2], [2,3], [3,4], [4,2], [5,6]], [ 4, 2 ] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindRedundantConnection(string name, int[][] edges, int[] want)
    {
        int[] got = RedundantConnection.FindRedundantConnection(edges);
        Assert.True(got.SequenceEqual(want), $"{name}: got {string.Join(",", got)}, want {string.Join(",", want)}");
    }
}
