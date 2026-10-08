namespace DsaPatterns.TwoPointers;

public class FindNonDuplicatesTests
{
    public static TheoryData<int[], int[], int> Cases =>
        new()
        {
            { [2, 3, 3, 3, 6, 9, 9], [2, 3, 6, 9], 4 },
            { [2, 2, 2, 11], [2, 11], 2 },
            { [1, 2, 2], [1, 2], 2 },
            { [0, 0, 1, 1, 1, 2, 2, 3, 3, 4], [0, 1, 2, 3, 4], 5 },
            { [1], [1], 1 },
            { [1, 2, 3], [1, 2, 3], 3 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MoveElements(int[] input, int[] expected, int length)
    {
        int[] arr = [.. input];

        int got = FindNonDuplicates.MoveElements(arr);

        Assert.Equal(length, got);
        Assert.Equal(expected, arr.Take(got));
    }
}
