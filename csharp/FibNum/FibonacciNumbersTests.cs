namespace DsaPatterns.FibNum;

public class FibonacciNumbersTests
{
    public static TheoryData<string, int, long> Cases =>
        new()
        {
            { "Example 1", 0, 0 },
            { "Example 2", 1, 1 },
            { "Example 3", 2, 1 },
            { "Example 4", 3, 2 },
            { "Example 5", 4, 3 },
            { "Example 6", 55, 139583862445 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CalculateFibonacci(string name, int n, long want)
    {
        long got = FibonacciNumbers.CalculateFibonacci(n);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
