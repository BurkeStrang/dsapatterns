namespace DsaPatterns.ModifiedBinarySearch;

public class BitonicArrayTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [1, 3, 8, 4, 3], 4, 3 },
            { "Example 2", [3, 8, 3, 1], 8, 1 },
            { "Example 3", [1, 3, 8, 12], 12, 3 },
            { "Example 4", [10, 9, 8], 10, 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SearchBitonic(string name, int[] arr, int key, int want)
    {
        int got = BitonicArray.SearchBitonic(arr, key);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
