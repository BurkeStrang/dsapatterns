namespace DsaPatterns.TopologicalSort;

public class TopSortTests
{
    // want is one valid order; there can be several
    public static TheoryData<string, int, int[][], int[]> Cases =>
        new()
        {
            {
                "Test Case 1",
                6,
                [
                    [5, 2],
                    [5, 0],
                    [4, 0],
                    [4, 1],
                    [2, 3],
                    [3, 1],
                ],
                [5, 4, 2, 3, 1, 0]
            },
            {
                "Test Case 2",
                4,
                [
                    [0, 1],
                    [1, 2],
                    [2, 3],
                ],
                [0, 1, 2, 3]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Sort(string name, int vertices, int[][] edges, int[] want)
    {
        List<int> got = TopSort.Sort(vertices, edges);

        Assert.True(
            Shared.IsTopologicalOrder(got, vertices, edges),
            $"{name}: got {Shared.Format(got)}, "
                + $"want something like {Shared.Format(want)}"
        );
    }
}
