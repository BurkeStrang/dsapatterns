namespace DsaPatterns.Subsets;

public class BalanceParenthesesTests
{
    public static TheoryData<string, int, string[]> Cases =>
        new() { { "example 1", 2, ["(())", "()()"] } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void GenerateValidParentheses(string name, int num, string[] want)
    {
        List<string> got = BalanceParentheses.GenerateValidParentheses(num);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
