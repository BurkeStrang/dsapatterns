namespace DsaPatterns.MonotonicStack;

public class RemoveAdjacentDupsTests
{
    public static TheoryData<string, string, string> Cases =>
        new()
        {
            { "empty string", "", "" },
            { "no duplicates", "abcd", "abcd" },
            { "all removed", "abccba", "" },
            { "simple pair", "aabb", "" },
            { "single removal", "foobar", "fbar" },
            { "triple duplicate", "fooobar", "fobar" },
            { "nested removals", "azxxzy", "ay" },
            { "single char", "a", "a" },
            { "all same", "aaaa", "" },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void RemoveDuplicates(string name, string s, string want)
    {
        string got = RemoveAdjacentDups.RemoveDuplicates(s);

        Assert.True(got == want, $"{name}: got \"{got}\", want \"{want}\"");
    }
}
