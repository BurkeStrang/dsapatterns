namespace DsaPatterns.BitwiseXor;

public class ComplementBase10Tests
{
    public static TheoryData<string, int, int> Cases =>
        new()
        {
            // number: 5 (binary 101) -> complement: 2 (binary 010)
            { "Example 1", 5, 2 },
            // number: 7 (binary 111) -> complement: 0 (binary 000)
            { "Example 2", 7, 0 },
            // number: 10 (binary 1010) -> complement: 5 (binary 0101)
            { "Example 3", 10, 5 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void BitwiseComplement(string name, int num, int want)
    {
        int got = ComplementBase10.BitwiseComplement(num);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
