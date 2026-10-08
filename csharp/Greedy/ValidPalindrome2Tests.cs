namespace DsaPatterns.Greedy;

public class ValidPalindrome2Tests
{
    public static TheoryData<string, string, bool> Cases =>
        new()
        {
            { "Example 1", "racecar", true },
            { "Example 2", "abeccdeba", true },
            { "Example 3", "abcdef", false },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void IsPalindromePossible(string name, string input, bool want)
    {
        bool got = ValidPalindrome2.IsPalindromePossible(input);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
