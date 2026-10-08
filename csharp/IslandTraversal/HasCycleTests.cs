namespace DsaPatterns.IslandTraversal;

public class HasCycleTests
{
    public static TheoryData<string, char[][], bool> Cases =>
        new()
        {
            {
                "no cycle",
                [
                    ['A', 'B', 'C'],
                    ['D', 'E', 'F'],
                    ['G', 'H', 'I'],
                ],
                false
            },
            {
                "simple cycle",
                [
                    ['A', 'A', 'A'],
                    ['A', 'B', 'A'],
                    ['A', 'A', 'A'],
                ],
                true
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MatrixHasCycle(string name, char[][] matrix, bool want)
    {
        bool got = HasCycle.MatrixHasCycle(matrix);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
