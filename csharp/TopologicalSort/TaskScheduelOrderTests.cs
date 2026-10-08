namespace DsaPatterns.TopologicalSort;

public class TaskScheduelOrderTests
{
    // want is one valid order (there can be several), or empty when the tasks
    // can't be scheduled
    public static TheoryData<string, int, int[][], int[]> Cases =>
        new()
        {
            {
                "Test Case 1",
                6,
                [
                    [2, 5],
                    [0, 5],
                    [0, 4],
                    [1, 4],
                    [3, 2],
                    [1, 3],
                ],
                [0, 1, 4, 3, 2, 5]
            },
            {
                "Test Case 2",
                3,
                [
                    [0, 1],
                    [1, 2],
                ],
                [0, 1, 2]
            },
            {
                "Test Case 3",
                3,
                [
                    [0, 1],
                    [1, 2],
                    [2, 0],
                ],
                []
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindOrder(
        string name,
        int tasks,
        int[][] prerequisites,
        int[] want
    )
    {
        List<int> got = TaskScheduelOrder.FindOrder(tasks, prerequisites);

        bool ok =
            want.Length == 0
                ? got.Count == 0
                : Shared.IsTopologicalOrder(got, tasks, prerequisites);
        Assert.True(
            ok,
            $"{name}: got {Shared.Format(got)}, "
                + $"want something like {Shared.Format(want)}"
        );
    }
}
