namespace DsaPatterns.KnapsackDp;

public class TargetSumTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [1, 1, 2, 3], 1, 3 },
            { "Example 2", [1, 2, 7, 1], 9, 2 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindTargetSubsets(string name, int[] num, int target, int want)
    {
        int got = TargetSum.FindTargetSubsets(num, target);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
