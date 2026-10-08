namespace DsaPatterns.Greedy;

public class RemoveDupTests
{
    public static TheoryData<string, string, string> Cases =>
        new()
        {
            { "Example 1", "babac", "abc" },
            { "Example 2", "zabccde", "zabcde" },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void RemoveDuplicateLetters(string name, string s, string want)
    {
        string got = RemoveDup.RemoveDuplicateLetters(s);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
