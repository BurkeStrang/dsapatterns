namespace DsaPatterns.Graphs;

public class NumOfProvincesTests
{
    public static TheoryData<string, int[][], int> Cases =>
        new()
        {
            {
                "Example 1: Two provinces",
                [
                    [1, 1, 0],
                    [1, 1, 0],
                    [0, 0, 1],
                ],
                2
            },
            {
                "Example 2: Three provinces",
                [
                    [1, 0, 0],
                    [0, 1, 0],
                    [0, 0, 1],
                ],
                3
            },
            {
                "Example 3: Two provinces",
                [
                    [1, 0, 0, 1],
                    [0, 1, 1, 0],
                    [0, 1, 1, 0],
                    [1, 0, 0, 1],
                ],
                2
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindProvinces(string name, int[][] isConnected, int want)
    {
        int got = NumOfProvinces.FindProvinces(isConnected);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
