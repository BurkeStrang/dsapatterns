namespace DsaPatterns.ReverseLinkedList;

public class ReverseAltKSublistTests
{
    public static TheoryData<string, int[], int, int[]> Cases =>
        new()
        {
            {
                "reverse every alternate 2 nodes",
                [1, 2, 3, 4, 5, 6],
                2,
                [2, 1, 3, 4, 6, 5]
            },
            {
                "reverse every alternate 3 nodes",
                [1, 2, 3, 4, 5, 6, 7],
                3,
                [3, 2, 1, 4, 5, 6, 7]
            },
            { "k greater than length", [1, 2], 5, [2, 1] },
            { "single node", [1], 2, [1] },
            { "empty list", [], 2, [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void ReverseAlt(string name, int[] head, int k, int[] want)
    {
        List<int> got = Shared.ToValues(
            ReverseAltKSublist.ReverseAlt(Shared.ToList(head), k)
        );

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
