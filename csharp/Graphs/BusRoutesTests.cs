namespace DsaPatterns.Graphs;

public class BusRoutesTests
{
    public static TheoryData<string, int[][], int, int, int> Cases =>
        new()
        {
            {
                "example 1",
                [
                    [1, 2, 7],
                    [3, 6, 7],
                ],
                1,
                6,
                2
            },
            {
                "example 2",
                [
                    [7, 12],
                    [4, 5, 15],
                    [6],
                    [15, 19],
                    [9, 12, 13],
                ],
                15,
                12,
                -1
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void NumBusesToDestination(
        string name,
        int[][] routes,
        int source,
        int target,
        int want
    )
    {
        int got = BusRoutes.NumBusesToDestination(routes, source, target);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
