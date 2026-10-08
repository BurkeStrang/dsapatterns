namespace DsaPatterns.FastAndSlowPointers;

public class LinkedListCycleTests
{
    // each case is: name, values, index the last node links back to, want
    public static TheoryData<string, int[], int, bool> Cases =>
        new()
        {
            { "no cycle", [1, 2, 3], -1, false },
            { "cycle exists", [1, 2, 3], 0, true },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void HasCycle(string name, int[] vals, int cycleStart, bool want)
    {
        bool got = LinkedListCycle.HasCycle(Shared.ToList(vals, cycleStart));

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
