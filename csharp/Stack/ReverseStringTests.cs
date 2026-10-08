namespace DsaPatterns.Stack;

public class ReverseStringTests
{
    public static TheoryData<string, string, string> Cases =>
        new()
        {
            { "Example 1", "Hello, World!", "!dlroW ,olleH" },
            { "Example 2", "OpenAI", "IAnepO" },
            { "Example 3", "Stacks are fun!", "!nuf era skcatS" },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Reverse(string name, string input, string want)
    {
        string got = ReverseString.Reverse(input);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
