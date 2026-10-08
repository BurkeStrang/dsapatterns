namespace DsaPatterns.ModifiedBinarySearch;

public class MinDiffTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [4, 6, 10], 7, 6 },
            { "Example 2", [4, 6, 10], 4, 4 },
            { "Example 3", [1, 3, 8, 10, 15], 12, 10 },
            { "Example 4", [4, 6, 10], 17, 10 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SearchMinDiff(string name, int[] arr, int key, int want)
    {
        int got = MinDiff.SearchMinDiff(arr, key);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
