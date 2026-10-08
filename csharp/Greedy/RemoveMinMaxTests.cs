namespace DsaPatterns.Greedy;

public class RemoveMinMaxTests
{
    public static TheoryData<string, int[], int> Cases =>
        new() { { "Example 1", [3, 2, 5, 1, 4], 3 } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MinMoves(string name, int[] nums, int want)
    {
        int got = RemoveMinMax.MinMoves(nums);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
