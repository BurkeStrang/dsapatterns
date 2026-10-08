namespace DsaPatterns.Graphs;

public class FindEventualStateTests
{
    public static TheoryData<string, int[][], int[]> Cases =>
        new()
        {
            {
                "Example 1: [3,4,5,6]",
                [
                    [1, 2],
                    [2, 3],
                    [2],
                    [],
                    [5],
                    [6],
                    [],
                ],
                [3, 4, 5, 6]
            },
            {
                "Example 2: [2,4,5,6]",
                [
                    [1, 2],
                    [2, 3],
                    [5],
                    [0],
                    [],
                    [],
                    [4],
                ],
                [2, 4, 5, 6]
            },
            {
                "Example 3: [0,1,2,3,4]",
                [
                    [1, 2, 3],
                    [2, 3],
                    [3],
                    [],
                    [0, 1, 2],
                ],
                [0, 1, 2, 3, 4]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void EventualSafeNodes(string name, int[][] graph, int[] want)
    {
        List<int> got = FindEventualState.EventualSafeNodes(graph);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
