namespace DsaPatterns.Subsets;

public class CountBstTests
{
    public static TheoryData<string, int, int> Cases =>
        new() { { "Example 1", 2, 2 }, { "Example 2", 3, 5 } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CountTrees(string name, int n, int want)
    {
        int got = CountBst.CountTrees(n);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
