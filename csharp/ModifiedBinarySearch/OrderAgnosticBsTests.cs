namespace DsaPatterns.ModifiedBinarySearch;

public class OrderAgnosticBsTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "ascending - key found in middle", [1, 3, 5, 7, 9], 5, 2 },
            { "ascending - key found at start", [1, 3, 5, 7, 9], 1, 0 },
            { "ascending - key found at end", [1, 3, 5, 7, 9], 9, 4 },
            { "ascending - key not found", [1, 3, 5, 7, 9], 4, -1 },
            { "descending - key found in middle", [9, 7, 5, 3, 1], 5, 2 },
            { "descending - key found at start", [9, 7, 5, 3, 1], 9, 0 },
            { "descending - key found at end", [9, 7, 5, 3, 1], 1, 4 },
            { "descending - key not found", [9, 7, 5, 3, 1], 4, -1 },
            { "single element - found", [42], 42, 0 },
            { "single element - not found", [42], 7, -1 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void DescOrAscSearch(string name, int[] arr, int key, int want)
    {
        int got = OrderAgnosticBs.DescOrAscSearch(arr, key);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
