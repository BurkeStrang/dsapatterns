namespace DsaPatterns.Subsets;

public class DiffWaysToEvaluateTests
{
    public static TheoryData<string, string, int[]> Cases =>
        new()
        {
            { "parentheses addition", "2+3*2", [8, 10] },
            { "parentheses multiple", "2*4-3*5", [-22, 10, -7, 10, 25] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void DiffWaysToEvaluateExpression(
        string name,
        string input,
        int[] want
    )
    {
        List<int> got = DiffWaysToEvaluate.DiffWaysToEvaluateExpression(input);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
