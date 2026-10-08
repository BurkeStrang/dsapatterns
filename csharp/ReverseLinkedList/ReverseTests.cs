namespace DsaPatterns.ReverseLinkedList;

public class ReverseTests
{
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            { "multiple nodes", [1, 2, 3], [3, 2, 1] },
            { "single node", [1], [1] },
            { "empty list", [], [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void ReverseList(string name, int[] head, int[] want)
    {
        List<int> got = Shared.ToValues(
            Reverse.ReverseList(Shared.ToList(head))
        );

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
