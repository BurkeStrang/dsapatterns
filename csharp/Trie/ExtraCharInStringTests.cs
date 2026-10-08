namespace DsaPatterns.Trie;

public class ExtraCharInStringTests
{
    public static TheoryData<string, string, string[], int> Cases =>
        new()
        {
            { "Test Case 1", "amazingracecar", ["race"], 10 },
            { "Test Case 2", "amazingracecar", ["race", "car"], 7 },
            { "Test Case 3", "bookkeeperreading", ["keep", "read"], 9 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MinExtraChar(
        string name,
        string s,
        string[] dictionary,
        int want
    )
    {
        ExtraCharInString solution = new();

        int got = solution.MinExtraChar(s, dictionary);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
