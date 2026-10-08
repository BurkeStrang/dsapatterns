namespace DsaPatterns.ModifiedBinarySearch;

public class BitonicArrayMaxTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [1, 3, 8, 12, 4, 2], 12 },
            { "Example 2", [3, 8, 3, 1], 8 },
            { "Example 3", [1, 3, 8, 12], 12 },
            { "Example 4", [10, 9, 8], 10 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMaxInBitonicArray(string name, int[] arr, int want)
    {
        int got = BitonicArrayMax.FindMaxInBitonicArray(arr);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
