namespace DsaPatterns.Greedy;

public class MinAddToMakeParenTests
{
    public static TheoryData<string, string, int> Cases =>
        new() { { "Example 1", "(()", 1 } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MinAddToMakeValid(string name, string s, int want)
    {
        int got = MinAddToMakeParen.MinAddToMakeValid(s);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
