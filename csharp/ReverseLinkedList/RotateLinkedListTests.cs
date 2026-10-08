namespace DsaPatterns.ReverseLinkedList;

public class RotateLinkedListTests
{
    public static TheoryData<string, int[], int, int[]> Cases =>
        new()
        {
            { "rotate by 2", [1, 2, 3, 4, 5], 2, [4, 5, 1, 2, 3] },
            { "rotate by 0 (no change)", [1, 2, 3], 0, [1, 2, 3] },
            { "rotate by length (no change)", [1, 2, 3], 3, [1, 2, 3] },
            { "rotate by more than length", [1, 2, 3], 5, [2, 3, 1] },
            { "single node", [1], 1, [1] },
            { "empty list", [], 3, [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Rotate(string name, int[] head, int rotations, int[] want)
    {
        List<int> got = Shared.ToValues(
            RotateLinkedList.Rotate(Shared.ToList(head), rotations)
        );

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
