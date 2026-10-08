namespace DsaPatterns.SlidingWindow;

public class PermutationsInStringTests
{
    public static TheoryData<string, string, string, bool> Cases =>
        new()
        {
            { "Example 1", "oidbcaf", "abc", true },
            { "Example 2", "odicf", "dc", false },
            { "Example 3", "bcdxabcdy", "bcdyabcdx", true },
            { "Example 4", "aaacb", "abc", true },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindPermutation(
        string name,
        string str,
        string pattern,
        bool want
    )
    {
        bool got = PermutationsInString.FindPermutation(str, pattern);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
