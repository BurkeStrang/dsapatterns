namespace DsaPatterns.Stack;

public class BalancedParenthesesTests
{
    public static TheoryData<string, string, bool> Cases =>
        new()
        {
            { "Example 1 - balanced", "{[()]}", true },
            { "Example 2 - not balanced", "{[}]", false },
            { "Example 3 - not balanced", "(]", false },
            { "Empty string - balanced", "", true },
            { "Single type - balanced", "()[]{}", true },
            { "Single type - not balanced", "(((", false },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void ValidParentheses(string name, string s1, bool want)
    {
        bool got = BalancedParentheses.ValidParentheses(s1);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
