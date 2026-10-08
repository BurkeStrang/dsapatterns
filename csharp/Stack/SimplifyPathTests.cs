namespace DsaPatterns.Stack;

public class SimplifyPathTests
{
    public static TheoryData<string, string, string> Cases =>
        new()
        {
            { "Example 1", "/a//b////c/d//././/..", "/a/b/c" },
            { "Example 2", "/../", "/" },
            { "Example 3", "/home//foo/", "/home/foo" },
            { "Root only", "/", "/" },
            { "Multiple .. at root", "/../../..", "/" },
            { "Dot only", "/./././.", "/" },
            { "Trailing slash", "/a/b/c/", "/a/b/c" },
            { "Complex", "/a/./b/../../c/", "/c" },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Simplify(string name, string path, string want)
    {
        string got = SimplifyPath.Simplify(path);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
