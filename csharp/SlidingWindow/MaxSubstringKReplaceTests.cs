namespace DsaPatterns.SlidingWindow;

public class MaxSubstringKReplaceTests
{
    public static TheoryData<string, string, int, int> Cases =>
        new()
        {
            { "Example 1", "aabccbb", 2, 5 },
            { "Example 2", "abbcb", 1, 4 },
            { "Example 3", "abccde", 1, 3 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MaxLengthReplace(string name, string str, int k, int want)
    {
        int got = MaxSubstringKReplace.MaxLengthReplace(str, k);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
