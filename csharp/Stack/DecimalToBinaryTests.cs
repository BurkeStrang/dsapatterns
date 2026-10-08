namespace DsaPatterns.Stack;

public class DecimalToBinaryTests
{
    public static TheoryData<string, int, string> Cases =>
        new()
        {
            { "Example 1", 2, "10" },
            { "Example 2", 7, "111" },
            { "Example 3", 18, "10010" },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void ToBinary(string name, int num, string want)
    {
        string got = DecimalToBinary.ToBinary(num);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
