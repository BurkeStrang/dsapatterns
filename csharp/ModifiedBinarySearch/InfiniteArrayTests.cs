namespace DsaPatterns.ModifiedBinarySearch;

public class InfiniteArrayTests
{
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            {
                "Example 1",
                [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30],
                16,
                6
            },
            {
                "Example 2",
                [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30],
                11,
                -1
            },
            { "Example 3", [1, 3, 8, 10, 15], 15, 4 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SearchInfiniteSortedArray(
        string name,
        int[] arr,
        int key,
        int want
    )
    {
        ArrayReader reader = new(arr);

        int got = InfiniteArray.SearchInfiniteSortedArray(reader, key);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
