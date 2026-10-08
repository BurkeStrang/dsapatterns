namespace DsaPatterns.TopKElements;

public class SumOfElementsTests
{
    public static TheoryData<string, int[], int, int, int> Cases =>
        new() { { "basic test", [1, 3, 12, 5, 15, 11], 3, 6, 23 } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindSumOfElements(
        string name,
        int[] nums,
        int k1,
        int k2,
        int want
    )
    {
        int got = SumOfElements.FindSumOfElements(nums, k1, k2);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
