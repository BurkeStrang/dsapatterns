namespace DsaPatterns.HashMaps;

public class FirstNonRepeatingCharTests
{
    public static TheoryData<string, string, int> Cases =>
        new()
        {
            { "Example 1: apple", "apple", 0 },
            { "Example 2: abcab", "abcab", 2 },
            { "Example 3: abab", "abab", -1 },
            { "Single character", "z", 0 },
            { "All unique", "abcdef", 0 },
            { "Last unique", "aabbc", 4 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FirstUniqChar(string name, string str, int want)
    {
        int got = FirstNonRepeatingChar.FirstUniqChar(str);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
