namespace DsaPatterns.TwoHeaps;

public class MaxCapitalTests
{
    public static TheoryData<string, int[], int[], int, int, int> Cases =>
        new()
        {
            { "basic example", [0, 1, 2], [1, 2, 3], 2, 1, 6 },
            {
                "not enough capital for any project",
                [5, 10, 15],
                [1, 2, 3],
                3,
                0,
                0
            },
            {
                "all projects affordable from start",
                [0, 0, 0],
                [1, 2, 3],
                2,
                0,
                5
            },
            { "single project", [0], [5], 1, 0, 5 },
            {
                "chain of unlocking projects",
                [0, 1, 2, 3],
                [1, 1, 1, 1],
                4,
                0,
                4
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMaximumCapital(
        string name,
        int[] capital,
        int[] profits,
        int numberOfProjects,
        int initialCapital,
        int expected
    )
    {
        int result = MaxCapital.FindMaximumCapital(
            capital,
            profits,
            numberOfProjects,
            initialCapital
        );

        Assert.True(
            result == expected,
            $"{name}: got {result}, expected {expected}"
        );
    }
}
