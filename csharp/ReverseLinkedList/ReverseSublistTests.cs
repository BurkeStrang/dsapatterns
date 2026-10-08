namespace DsaPatterns.ReverseLinkedList;

public class ReverseSublistTests
{
    public static TheoryData<string, int[], int, int, int[]> Cases =>
        new()
        {
            {
                "reverse middle sublist",
                [1, 2, 3, 4, 5],
                2,
                4,
                [1, 4, 3, 2, 5]
            },
            { "reverse entire list", [1, 2, 3], 1, 3, [3, 2, 1] },
            { "reverse single node (no change)", [1, 2], 2, 2, [1, 2] },
            { "reverse head only", [1, 2], 1, 1, [1, 2] },
            { "reverse tail only", [1, 2], 2, 2, [1, 2] },
            { "empty list", [], 1, 1, [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void ReverseSub(string name, int[] head, int p, int q, int[] want)
    {
        List<int> got = Shared.ToValues(
            ReverseSublist.ReverseSub(Shared.ToList(head), p, q)
        );

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
