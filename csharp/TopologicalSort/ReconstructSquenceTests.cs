namespace DsaPatterns.TopologicalSort;

public class ReconstructSquenceTests
{
    public static TheoryData<string, int[], int[][], bool> Cases =>
        new()
        {
            {
                "Example 1",
                [1, 2, 3, 4],
                [
                    [1, 2],
                    [2, 3],
                    [3, 4]
                ],
                true
            },
            {
                "Example 2",
                [1, 2, 3, 4],
                [
                    [1, 2],
                    [2, 3],
                    [2, 4]
                ],
                false
            },
            {
                "Example 3",
                [3, 1, 4, 2, 5],
                [
                    [3, 1, 5],
                    [1, 4, 2, 5]
                ],
                true
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CanConstructSequence(string name, int[] org, int[][] seqs, bool want)
    {
        bool got = ReconstructSequence.CanConstruct(org, seqs);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
