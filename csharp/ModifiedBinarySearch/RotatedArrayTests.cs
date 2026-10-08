namespace DsaPatterns.ModifiedBinarySearch;

public class RotatedArrayTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [10, 15, 1, 3, 8], 15, 1 },
            { "Example 2", [4, 5, 7, 9, 10, -1, 2], 10, 4 },
            { "Example 3", [10, 15, 1, 3, 8], 100, -1 },
            { "Example 4", [10, 15, 1, 3, 8], 1, 2 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SearchRotated(string name, int[] arr, int key, int want)
    {
        int got = RotatedArray.SearchRotated(arr, key);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
