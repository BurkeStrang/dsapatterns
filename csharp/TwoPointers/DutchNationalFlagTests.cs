namespace DsaPatterns.TwoPointers;

public class DutchNationalFlagTests
{
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            { "example1", [1, 0, 2, 1, 0], [0, 0, 1, 1, 2] },
            { "example2", [2, 2, 0, 1, 2, 0], [0, 0, 1, 2, 2, 2] },
            { "all zeros", [0, 0, 0], [0, 0, 0] },
            { "all twos", [2, 2, 2], [2, 2, 2] },
            { "already sorted", [0, 0, 1, 1, 2, 2], [0, 0, 1, 1, 2, 2] },
            { "single element", [1], [1] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Dutch(string name, int[] input, int[] want)
    {
        // copy input to avoid modifying test cases
        int[] got = DutchNationalFlag.Dutch([.. input]);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
