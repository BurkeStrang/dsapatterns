namespace DsaPatterns.Misc;

public class IsPrimeTests
{
    public static TheoryData<string, int, bool> IsPrimeCases =>
        new()
        {
            { "1", 1, false },
            { "2", 2, true },
            { "3", 3, true },
            { "4", 4, false },
            { "5", 5, true },
            { "167", 167, true },
        };

    public static TheoryData<string, int, int> CountPrimesCases =>
        new()
        {
            { "1", 1, 0 },
            { "10", 10, 4 },
            { "100", 100, 25 },
            { "1000", 1000, 168 },
            { "10000", 10000, 1229 },
        };

    public static TheoryData<string, int, int[]> GetPrimesCases =>
        new()
        {
            { "1", 1, [] },
            { "10", 10, [2, 3, 5, 7] },
            { "20", 20, [2, 3, 5, 7, 11, 13, 17, 19] },
            { "30", 30, [2, 3, 5, 7, 11, 13, 17, 19, 23, 29] },
            {
                "100",
                100,
                [
                    2,
                    3,
                    5,
                    7,
                    11,
                    13,
                    17,
                    19,
                    23,
                    29,
                    31,
                    37,
                    41,
                    43,
                    47,
                    53,
                    59,
                    61,
                    67,
                    71,
                    73,
                    79,
                    83,
                    89,
                    97,
                ]
            },
        };

    [Theory]
    [MemberData(nameof(IsPrimeCases))]
    public void IsPrimeNumber(string name, int n, bool want)
    {
        bool got = IsPrime.IsPrimeNumber(n);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }

    [Theory]
    [MemberData(nameof(CountPrimesCases))]
    public void CountPrimes(string name, int n, int want)
    {
        int got = IsPrime.CountPrimes(n);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }

    [Theory]
    [MemberData(nameof(GetPrimesCases))]
    public void GetPrimes(string name, int n, int[] want)
    {
        List<int> got = IsPrime.GetPrimes(n);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got [{string.Join(", ", got)}], "
                + $"want [{string.Join(", ", want)}]"
        );
    }
}
