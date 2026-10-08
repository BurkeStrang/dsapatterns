namespace DsaPatterns.HashMaps;

public class LongestPalindromeTests
{
    public static TheoryData<string, string, int> Cases =>
        new()
        {
            { "applepie", "applepie", 5 },
            { "aabbcc", "aabbcc", 6 },
            { "bananas", "bananas", 5 },
            { "single character", "a", 1 },
            { "all unique", "abcdef", 1 },
            { "all pairs", "aabb", 4 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void LongestPalindromeLength(string name, string s, int want)
    {
        int got = LongestPalindrome.LongestPalindromeLength(s);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
