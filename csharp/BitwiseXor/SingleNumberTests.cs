namespace DsaPatterns.BitwiseXor;

public class SingleNumberTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [1, 4, 2, 1, 3, 2, 3], 4 },
            { "Example 2", [7, 9, 7], 9 },
            { "Example 3", [5, 6, 7, 5, 6], 7 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindSingleNumber(string name, int[] arr, int want)
    {
        int got = SingleNumber.FindSingleNumber(arr);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
