namespace DsaPatterns.ModifiedBinarySearch;

public class RotationCountTests
{
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "Example 1", [10, 15, 1, 3, 8], 2 },
            { "Example 2", [4, 5, 7, 9, 10, -1, 2], 5 },
            { "Example 3", [1, 3, 8, 10], 0 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CountRotations(string name, int[] arr, int want)
    {
        int got = RotationCount.CountRotations(arr);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
