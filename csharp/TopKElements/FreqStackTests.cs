namespace DsaPatterns.TopKElements;

public class FreqStackTests
{
    // each case is the numbers to push, then the values every pop should
    // return, in order
    public static TheoryData<string, int[], int[]> Cases =>
        new()
        {
            {
                "most frequent first, ties broken by most recent",
                [1, 2, 3, 2, 1, 2, 5],
                [2, 1, 2, 5, 3, 2, 1]
            },
            { "all distinct pops like a stack", [4, 7, 9], [9, 7, 4] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void PushThenPop(string name, int[] pushes, int[] want)
    {
        FreqStack stack = new();
        foreach (int num in pushes)
        {
            stack.Push(num);
        }

        List<int> got = [];
        for (int i = 0; i < want.Length; i++)
        {
            got.Add(stack.Pop());
        }

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
