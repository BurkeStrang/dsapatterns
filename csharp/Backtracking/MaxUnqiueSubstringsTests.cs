namespace DsaPatterns.Backtracking;

public class MaxUnqiueSubstringsTests
{
    public static TheoryData<string, string, int> Cases =>
        new()
        {
            { "Example 1", "ababccc", 5 },
            { "Example 2", "aba", 2 },
            { "Example 3", "aa", 1 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MaxUniqueSplit(string name, string str, int want)
    {
        int got = MaxUnqiueSubstrings.MaxUniqueSplit(str);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
