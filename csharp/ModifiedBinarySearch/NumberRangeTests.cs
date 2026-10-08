namespace DsaPatterns.ModifiedBinarySearch;

public class NumberRangeTests
{
    public static TheoryData<string, int[], int, int[]> Cases =>
        new()
        {
            { "example1", [4, 6, 6, 6, 9], 6, [1, 3] },
            { "example2", [1, 3, 8, 10, 15], 10, [3, 3] },
            { "example3", [1, 3, 8, 10, 15], 12, [-1, -1] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindRange(string name, int[] arr, int key, int[] want)
    {
        int[] got = NumberRange.FindRange(arr, key);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got [{got[0]}, {got[1]}], want [{want[0]}, {want[1]}]"
        );
    }
}
