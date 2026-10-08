namespace DsaPatterns.FibNum;

public class NumFactorsTests
{
    public static TheoryData<string, int, int> Cases =>
        new() { { "Example 1", 4, 4 }, { "Example 2", 5, 6 } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Factors(string name, int n, int want)
    {
        int got = NumFactors.Factors(n);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
