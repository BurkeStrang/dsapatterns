namespace DsaPatterns.BitwiseXor;

public class MissingNumberTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [1, 2, 3, 5], 4 },
            { "Example 2", [1, 2, 4, 5], 3 },
            { "Example 3", Enumerable.Range(1, 20).ToArray(), 21 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMissingNumber(string name, int[] arr, int want)
    {
        int got = MissingNumber.FindMissingNumber(arr);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
