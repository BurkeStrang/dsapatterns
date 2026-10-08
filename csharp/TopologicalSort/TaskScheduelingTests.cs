namespace DsaPatterns.TopologicalSort;

public class TaskScheduelingTests
{
    public static TheoryData<string, int, int[][], bool> Cases =>
        new()
        {
            {
                "Test Case 1",
                3,
                [
                    [0, 1],
                    [1, 2],
                ],
                true
            },
            {
                "Test Case 2",
                3,
                [
                    [0, 1],
                    [1, 2],
                    [2, 0],
                ],
                false
            },
            {
                "Test Case 3",
                4,
                [
                    [0, 1],
                    [1, 2],
                    [2, 3],
                ],
                true
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void IsSchedulingPossible(
        string name,
        int tasks,
        int[][] prerequisites,
        bool want
    )
    {
        bool got = TaskSchedueling.IsSchedulingPossible(tasks, prerequisites);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
