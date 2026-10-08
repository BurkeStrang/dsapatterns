namespace DsaPatterns.MonotonicStack;

public class RemoveNodesFromLinkedListTests
{
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            { "Example 1", [5, 3, 7, 4, 2, 1], [7, 4, 2, 1] },
            { "Example 2", [1, 2, 3, 4, 5], [5] },
            { "Example 3", [5, 4, 3, 2, 1], [5, 4, 3, 2, 1] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void RemoveNodes(string name, int[] head, int[] want)
    {
        List<int> got = Shared.ListToValues(
            RemoveNodesFromLinkedList.RemoveNodes(Shared.BuildList(head))
        );

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
