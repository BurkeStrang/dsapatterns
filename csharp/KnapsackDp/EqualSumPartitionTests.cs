namespace DsaPatterns.KnapsackDp;

public class EqualSumPartitionTests
{
    public static TheoryData<string, int[], bool> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3, 4], true },
            { "Example 2", [1, 1, 3, 4, 7], true },
            { "Example 3", [2, 3, 4, 6], false },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CanPartition(string name, int[] nums, bool want)
    {
        bool got = EqualSumPartition.CanPartition(nums);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
