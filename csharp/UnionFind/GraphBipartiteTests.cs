namespace DsaPatterns.UnionFind;

public class GraphBipartiteTests
{
    public static TheoryData<string, int[][], bool> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [1, 3],
                    [0, 2],
                    [1, 3],
                    [0, 2],
                ],
                true
            },
            {
                "Example 2",
                [
                    [1],
                    [0],
                    [3],
                    [2],
                ],
                true
            },
            {
                "Example 3",
                [
                    [1, 2, 3],
                    [0, 2],
                    [0, 1, 3],
                    [0, 2],
                ],
                false
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void IsBipartite(string name, int[][] edges, bool want)
    {
        bool got = GraphBipartite.IsBipartite(edges);
        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
