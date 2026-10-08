namespace DsaPatterns.SlidingWindow;

public class SmallestWindowSubstringTests
{
    public static TheoryData<string, string, string, string> Cases =>
        new()
        {
            { "Example 1", "aabdec", "abc", "abdec" },
            { "Example 2", "aabdec", "abac", "aabdec" },
            { "Example 3", "abdbca", "abc", "bca" },
            { "Example 4", "adcad", "abc", "" },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindSubstring(
        string name,
        string str,
        string pattern,
        string want
    )
    {
        string got = SmallestWindowSubstring.FindSubstring(str, pattern);

        Assert.True(got == want, $"{name}: got \"{got}\", want \"{want}\"");
    }
}
