namespace DsaPatterns.SlidingWindow;

public class LongestSubstringWithKCharsTests
{
    public static TheoryData<string, string, int, int> Cases =>
        new()
        {
            { "Example 1", "araaci", 2, 4 },
            { "Example 2", "araaci", 1, 2 },
            { "Example 3", "cbbebi", 3, 5 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindLength(string name, string str, int k, int want)
    {
        int got = LongestSubstringWithKChars.FindLength(str, k);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
