namespace DsaPatterns.FastAndSlowPointers;

public class StartOfCycleTests
{
    // each case is: name, values, index the last node links back to (which is
    // also the node we expect back), or -1 for no cycle
    public static TheoryData<string, int[], int> Cases =>
        new()
        {
            { "cycle at node 2", [1, 2, 3, 4], 1 },
            { "no cycle", [1, 2, 3], -1 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindCycleStart(string name, int[] vals, int cycleStart)
    {
        ListNode? head = Shared.ToList(vals, cycleStart);
        ListNode? want = null;
        if (cycleStart != -1)
        {
            want = head;
            for (int i = 0; i < cycleStart; i++)
            {
                want = want!.Next;
            }
        }

        ListNode? got = StartOfCycle.FindCycleStart(head);

        Assert.True(
            ReferenceEquals(got, want),
            $"{name}: got node {got?.Val}, want node {want?.Val}"
        );
    }
}
