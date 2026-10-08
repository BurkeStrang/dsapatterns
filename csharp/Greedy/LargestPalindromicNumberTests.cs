namespace DsaPatterns.Greedy;

public class LargestPalindromicNumberTests
{
    public static TheoryData<string, string, string> Cases =>
        new()
        {
            { "Example 1", "323211444", "432141234" },
            { "Example 3", "54321", "5" },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void LargestPalindromic(string name, string s, string want)
    {
        string got = LargestPalindromicNumber.LargestPalindromic(s);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
