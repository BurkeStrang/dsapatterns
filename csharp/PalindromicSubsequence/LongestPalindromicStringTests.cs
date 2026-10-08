namespace DsaPatterns.PalindromicSubsequence;

public class LongestPalindromicStringTests
{
    public static TheoryData<string, string, int> Cases =>
        new()
        {
            { "Example 1", "abdbca", 3 },
            { "Example 2", "cddpd", 3 },
            { "Example 3", "pqr", 1 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindLpStringLength(string name, string st, int want)
    {
        int got = LongestPalindromicString.FindLpStringLength(st);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
