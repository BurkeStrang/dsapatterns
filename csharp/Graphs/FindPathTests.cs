namespace DsaPatterns.Graphs;

public class FindPathTests
{
    public static TheoryData<string, int, int[][], int, int, bool> Cases =>
        new()
        {
            {
                "path exists simple",
                4,
                [
                    [0, 1],
                    [1, 2],
                    [2, 3],
                ],
                0,
                3,
                true
            },
            {
                "no path between disconnected components",
                4,
                [
                    [0, 1],
                    [2, 3],
                ],
                0,
                3,
                false
            },
            {
                "no path with isolated nodes",
                5,
                [
                    [0, 1],
                    [3, 4],
                ],
                0,
                4,
                false
            },
            { "single node graph", 1, [], 0, 0, true },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void ValidPath(
        string name,
        int n,
        int[][] edges,
        int start,
        int end,
        bool want
    )
    {
        bool got = FindPath.ValidPath(n, edges, start, end);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
