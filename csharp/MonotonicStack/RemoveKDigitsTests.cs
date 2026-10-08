namespace DsaPatterns.MonotonicStack;

public class RemoveKDigitsTests
{
    public static TheoryData<string, string, int, string> Cases =>
        new()
        {
            { "Example 1", "1432219", 3, "1219" },
            { "Example 2", "10200", 1, "200" },
            { "Example 3", "1901042", 4, "2" },
            { "Remove all digits", "10", 2, "0" },
            { "Leading zeros after removal", "100200", 1, "200" },
            { "No removal needed", "12345", 0, "12345" },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void RemoveKdigits(string name, string num, int k, string want)
    {
        string got = RemoveKDigits.RemoveKdigits(num, k);

        Assert.True(got == want, $"{name}: got \"{got}\", want \"{want}\"");
    }
}
