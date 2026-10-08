namespace DsaPatterns.PalindromicSubsequence;

public class PalindromicPartitionTests
{
    public static TheoryData<string, string, int> Cases =>
        new()
        {
            { "Example 1", "abdbca", 3 },
            { "Example 2", "cddpd", 2 },
            { "Example 3", "pqr", 2 },
            { "Example 4", "pp", 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMppCuts(string name, string st, int want)
    {
        int got = PalindromicPartition.FindMppCuts(st);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
