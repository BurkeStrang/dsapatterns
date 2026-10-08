namespace DsaPatterns.ModifiedBinarySearch;

public class CeilingTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            { "Exmple 1", [4, 6, 10], 5, 1 },
            { "key exists in array", [1, 3, 8, 10, 15], 8, 2 },
            { "key between two elements", [1, 3, 8, 10, 15], 12, 4 },
            { "key smaller than all elements", [1, 3, 8, 10, 15], 0, 0 },
            { "key larger than all elements", [1, 3, 8, 10, 15], 20, -1 },
            { "key is smallest element", [1, 3, 8, 10, 15], 1, 0 },
            { "key is largest element", [1, 3, 8, 10, 15], 15, 4 },
            { "key just below a middle element", [2, 4, 6, 8, 10], 5, 2 },
            { "single element - key matches", [5], 5, 0 },
            { "single element - key is smaller", [5], 3, 0 },
            { "single element - key is larger", [5], 7, -1 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SearchCeilingOfANumber(
        string name,
        int[] arr,
        int key,
        int want
    )
    {
        int got = Ceiling.SearchCeilingOfANumber(arr, key);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
