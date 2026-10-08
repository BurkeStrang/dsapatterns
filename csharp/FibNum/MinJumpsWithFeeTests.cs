namespace DsaPatterns.FibNum;

public class MinJumpsWithFeeTests
{
    public static TheoryData<string, int[], int> Cases =>
        new() { { "Example 1", [1, 2, 5, 2, 1, 2], 3 } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMinFee(string name, int[] fee, int want)
    {
        int got = MinJumpsWithFee.FindMinFee(fee);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
