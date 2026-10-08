namespace DsaPatterns.TwoPointers;

public class SquareASortedArrayTests
{
    public static TheoryData<int[], int[]> Cases =>
        new()
        {
            { [-2, -1, 0, 2, 3], [0, 1, 4, 4, 9] },
            { [-3, -1, 0, 1, 2], [0, 1, 1, 4, 9] },
            { [0], [0] },
            { [-1], [1] },
            { [1, 2, 3], [1, 4, 9] },
            { [-4, -3, -2, -1], [1, 4, 9, 16] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MakeSquares(int[] input, int[] expected)
    {
        int[] result = SquareASortedArray.MakeSquares(input);

        Assert.Equal(expected, result);
    }
}
