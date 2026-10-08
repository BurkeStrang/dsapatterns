namespace DsaPatterns.FastAndSlowPointers;

public class RearangeListTests
{
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            { "even length list", [1, 2, 3, 4], [1, 4, 2, 3] },
            { "odd length list", [1, 2, 3], [1, 3, 2] },
            { "single node", [1], [1] },
            { "empty list", [], [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Rearange(string name, int[] head, int[] want)
    {
        List<int> got = Shared.ToValues(
            RearangeList.Rearange(Shared.ToList(head))
        );

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
