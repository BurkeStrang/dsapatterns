namespace DsaPatterns.TopologicalSort;

public class AlienDictionTests
{
    public static TheoryData<string, string[], string> Cases =>
        new()
        {
            {
                "Example 1",
                ["ba", "bc", "ac", "cab"],
                "bac"
            },
            {
                "Example 2",
                ["cab", "aaa", "aab"],
                "cab"
            },
            {
                "Example 3",
                ["ywx", "wz", "xww", "xz", "zyy", "zwz"],
                "ywxz"
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void AlienOrder(string name, string[] words, string want)
    {
        string got = AlienDiction.FindOrder(words);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
