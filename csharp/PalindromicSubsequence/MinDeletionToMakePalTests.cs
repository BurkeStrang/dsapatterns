namespace DsaPatterns.PalindromicSubsequence;

public class MinDeletionToMakePalTests
{
    public static TheoryData<string, string, int> Cases =>
        new()
        {
            { "Example 1", "abdbca", 1 },
            { "Example 2", "cddpd", 2 },
            { "Example 3", "pqr", 2 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMinimumDeletions(string name, string st, int want)
    {
        int got = MinDeletionToMakePal.FindMinimumDeletions(st);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
