namespace DsaPatterns.TopologicalSort;

public class TaskScheduelAllTests
{
    // want lists every valid ordering; they can come back in any order
    public static TheoryData<string, int, int[][], int[][]> Cases =>
        new()
        {
            {
                "Example 1: two orderings",
                4,
                [
                    [3, 2],
                    [3, 0],
                    [2, 0],
                    [2, 1],
                ],
                [
                    [3, 2, 0, 1],
                    [3, 2, 1, 0],
                ]
            },
            {
                "Example 2: one ordering",
                3,
                [
                    [0, 1],
                    [1, 2],
                ],
                [
                    [0, 1, 2],
                ]
            },
            {
                "Example 3: thirteen orderings",
                6,
                [
                    [2, 5],
                    [0, 5],
                    [0, 4],
                    [1, 4],
                    [3, 2],
                    [1, 3],
                ],
                [
                    [0, 1, 4, 3, 2, 5],
                    [0, 1, 3, 4, 2, 5],
                    [0, 1, 3, 2, 4, 5],
                    [0, 1, 3, 2, 5, 4],
                    [1, 0, 3, 4, 2, 5],
                    [1, 0, 3, 2, 4, 5],
                    [1, 0, 3, 2, 5, 4],
                    [1, 0, 4, 3, 2, 5],
                    [1, 3, 0, 2, 4, 5],
                    [1, 3, 0, 2, 5, 4],
                    [1, 3, 0, 4, 2, 5],
                    [1, 3, 2, 0, 5, 4],
                    [1, 3, 2, 0, 4, 5],
                ]
            },
            {
                "No prerequisites: every arrangement",
                3,
                [],
                [
                    [0, 1, 2],
                    [0, 2, 1],
                    [1, 0, 2],
                    [1, 2, 0],
                    [2, 0, 1],
                    [2, 1, 0],
                ]
            },
            {
                "Cyclic prerequisites: no ordering",
                3,
                [
                    [0, 1],
                    [1, 2],
                    [2, 0],
                ],
                []
            },
            { "No tasks", 0, [], [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void PrintOrders(
        string name,
        int tasks,
        int[][] prerequisites,
        int[][] want
    )
    {
        List<List<int>> got = TaskSchedulingAll.PrintOrders(
            tasks,
            prerequisites
        );

        List<string> gotOrders = got.Select(Shared.Format).Order().ToList();
        List<string> wantOrders = want.Select(Shared.Format).Order().ToList();
        Assert.True(
            gotOrders.SequenceEqual(wantOrders),
            $"{name}: got {gotOrders.Count} orderings "
                + $"[{string.Join(", ", gotOrders)}], "
                + $"want {wantOrders.Count} "
                + $"[{string.Join(", ", wantOrders)}]"
        );
    }
}
