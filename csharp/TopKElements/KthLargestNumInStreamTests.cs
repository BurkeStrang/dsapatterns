namespace DsaPatterns.TopKElements;

public class KthLargestNumInStreamTests
{
    public static TheoryData<string, int[], int, int, int> Cases =>
        new()
        {
            { "Example 1", [3, 1, 5, 12, 2, 11], 4, 6, 5 },
            { "Example 2", [3, 1, 5, 12, 2, 11], 4, 13, 5 },
            { "Example 3", [3, 1, 5, 12, 2, 11], 4, 4, 4 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Add(string name, int[] nums, int k, int num, int want)
    {
        KthLargestNumInStream stream = new(nums, k);

        int got = stream.Add(num);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
