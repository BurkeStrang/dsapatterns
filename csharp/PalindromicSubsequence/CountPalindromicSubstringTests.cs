namespace DsaPatterns.PalindromicSubsequence;

public class CountPalindromicSubstringTests
{
    public static TheoryData<string, string, int> Cases =>
        new()
        {
            { "Example1", "abdbca", 7 },
            // { "Example2", "cddpd", 7 },
            // { "Example3", "pqr", 3 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindCps(string name, string st, int want)
    {
        int got = CountPalindromicSubstring.FindCps(st);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
