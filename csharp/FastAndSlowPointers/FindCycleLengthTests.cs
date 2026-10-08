namespace DsaPatterns.FastAndSlowPointers;

public class FindCycleLengthTests
{
    // each case is: name, values, index the last node links back to, want
    public static TheoryData<string, int[], int, int> Cases =>
        new()
        {
            // cycle starts at the second node, length 3
            { "cycle of length 3", [1, 2, 3, 4], 1, 3 },
            { "no cycle", [1, 2, 3], -1, 0 },
            { "cycle of length 1 (self loop)", [1], 0, 1 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CycleLength(string name, int[] vals, int cycleStart, int want)
    {
        int got = FindCycleLength.CycleLength(Shared.ToList(vals, cycleStart));

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
