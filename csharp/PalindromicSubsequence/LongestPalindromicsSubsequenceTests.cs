namespace DsaPatterns.PalindromicSubsequence;

public class LongestPalindromicsSubsequenceTests
{
    public static TheoryData<string, string, int> Cases =>
        new() { { "Example 1", "abdbca", 5 }, { "Example 2", "cddpd", 3 } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindLpsLength(string name, string st, int want)
    {
        int got = LongestPalindromicsSubsequence.FindLpsLength(st);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
