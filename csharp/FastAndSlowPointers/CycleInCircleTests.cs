namespace DsaPatterns.FastAndSlowPointers;

public class CycleInCircleTests
{
    public static TheoryData<int[], bool> Cases =>
        new()
        {
            { [1, 2, -1, 2, 2], true }, // Example 1
            { [2, 2, -1, 2], true }, // Example 2
            { [2, 1, -1, -2], false }, // Example 3
            { [1, -1, 1, -1], false }, // No cycle, alternating directions
            { [3, 1, 2], true }, // Simple cycle
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void LoopExists(int[] arr, bool expected)
    {
        bool result = CycleInCircle.LoopExists(arr);

        Assert.Equal(expected, result);
    }
}
