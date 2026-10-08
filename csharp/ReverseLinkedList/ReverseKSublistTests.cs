namespace DsaPatterns.ReverseLinkedList;

public class ReverseKSublistTests
{
    public static TheoryData<string, int[], int, int[]> Cases =>
        new()
        {
            { "reverse every 2 nodes", [1, 2, 3, 4, 5], 2, [2, 1, 4, 3, 5] },
            { "reverse every 3 nodes", [1, 2, 3, 4, 5], 3, [3, 2, 1, 5, 4] },
            { "k greater than length", [1, 2], 5, [2, 1] },
            { "single node", [1], 2, [1] },
            { "empty list", [], 2, [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void ReverseKSub(string name, int[] head, int k, int[] want)
    {
        List<int> got = Shared.ToValues(
            ReverseKSublist.ReverseKSub(Shared.ToList(head), k)
        );

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
