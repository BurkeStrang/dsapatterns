namespace DsaPatterns.TwoPointers;

public class MinWindowSortTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [1, 2, 5, 3, 7, 10, 9, 12], 5 },
            { "Example 2", [1, 3, 2, 0, -1, 7, 10], 5 },
            { "Example 3", [1, 2, 3], 0 },
            { "Example 4", [3, 2, 1], 3 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MinSort(string name, int[] arr, int want)
    {
        int got = MinWindowSort.MinSort(arr);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
