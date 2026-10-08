namespace DsaPatterns.Stack;

public class SortingStackTests
{
    // stacks are written with the bottom element first and the top last
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            { "Example 1", [34, 3, 31, 98, 92, 23], [3, 23, 31, 34, 92, 98] },
            {
                "Example 2",
                [4, 3, 2, 10, 12, 1, 5, 6],
                [1, 2, 3, 4, 5, 6, 10, 12]
            },
            { "Example 3", [20, 10, -5, -1], [-5, -1, 10, 20] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SortStack(string name, int[] input, int[] want)
    {
        Stack<int> got = SortingStack.SortStack(new Stack<int>(input));

        // enumerating a stack starts at the top, so reverse it to get the
        // bottom element first
        int[] gotValues = got.Reverse().ToArray();
        Assert.True(
            gotValues.SequenceEqual(want),
            $"{name}: got {Shared.Format(gotValues)}, "
                + $"want {Shared.Format(want)}"
        );
    }
}
