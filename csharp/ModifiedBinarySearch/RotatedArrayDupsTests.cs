namespace DsaPatterns.ModifiedBinarySearch;

public class RotatedArrayDupsTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Example 1", [3, 7, 3, 3, 3], 7, 1 },
            { "Example 2", [3, 3, 3, 7, 3], 7, 3 },
            { "Example 3", [3, 3, 7, 3, 3], 7, 2 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SearchRotatedDups(string name, int[] arr, int key, int want)
    {
        int got = RotatedArrayDups.SearchRotatedDups(arr, key);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
