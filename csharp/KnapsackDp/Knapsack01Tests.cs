namespace DsaPatterns.KnapsackDp;

public class Knapsack01Tests
{
    public static TheoryData<string, int[], int[], int, int> Cases =>
        new() { { "Example", [4, 5, 3, 7], [2, 3, 1, 4], 5, 10 } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SolveKnapsack(
        string name,
        int[] profits,
        int[] weights,
        int capacity,
        int want
    )
    {
        int got = Knapsack01.SolveKnapsack(profits, weights, capacity);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
