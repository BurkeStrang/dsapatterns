namespace DsaPatterns.HashMaps;

public class MaxNumBalloonsTests
{
    public static TheoryData<string, string, int> Cases =>
        new()
        {
            { "Example 1", "balloonballoon", 2 },
            { "Example 2", "bbaall", 0 },
            { "Example 3", "balloonballoooon", 2 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MaxNumberOfBalloons(string name, string text, int want)
    {
        int got = MaxNumBalloons.MaxNumberOfBalloons(text);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
