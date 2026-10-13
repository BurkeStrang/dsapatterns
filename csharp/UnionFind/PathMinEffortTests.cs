namespace DsaPatterns.UnionFind;

public class PathMinEffortTests
{
    public static TheoryData<string, int[][], int> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [1, 2, 3],
                    [3, 8, 4],
                    [5, 3, 5],
                ],
                1
            },
            {
                "Example 2",
                [
                    [1, 2, 2],
                    [3, 3, 3],
                    [5, 3, 1],
                ],
                2
            },
            {
                "Example 3",
                [
                    [1, 1, 1],
                    [1, 1, 1],
                    [1, 1, 1],
                ],
                0
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindPathMinEffort(string name, int[][] edges, int want)
    {
        int got = PathMinEffot.MinimumEffortPath(edges);
        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
