namespace DsaPatterns.Greedy;

public class MaxLengthPairChainTests
{
    public static TheoryData<string, int[][], int> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [1, 2],
                    [3, 4],
                    [2, 3],
                ],
                2
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindLongestChain(string name, int[][] pairs, int want)
    {
        int got = MaxLengthPairChain.FindLongestChain(pairs);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
