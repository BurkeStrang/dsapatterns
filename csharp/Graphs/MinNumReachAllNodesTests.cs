namespace DsaPatterns.Graphs;

public class MinNumReachAllNodesTests
{
    public static TheoryData<string, int, int[][], int[]> Cases =>
        new()
        {
            {
                "Example 1",
                6,
                [
                    [0, 1],
                    [0, 2],
                    [2, 5],
                    [3, 4],
                    [4, 2],
                ],
                [0, 3]
            },
            { "Single node", 1, [], [0] },
            { "Disconnected nodes", 3, [], [0, 1, 2] },
            {
                "All nodes connected in a chain",
                4,
                [
                    [0, 1],
                    [1, 2],
                    [2, 3],
                ],
                [0]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindSmallestSetOfVertices(
        string name,
        int n,
        int[][] edges,
        int[] want
    )
    {
        List<int> got = MinNumReachAllNodes.FindSmallestSetOfVertices(n, edges);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
