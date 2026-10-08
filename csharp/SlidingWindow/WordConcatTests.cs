namespace DsaPatterns.SlidingWindow;

public class WordConcatTests
{
    public static TheoryData<string, string, string[], int[]> Cases =>
        new()
        {
            { "Example 1", "catfoxcat", ["cat", "fox"], [0, 3] },
            { "Example 2", "catcatfoxfox", ["cat", "fox"], [3] },
            { "No match", "abcdefg", ["hi", "jk"], [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindWordConcatenation(
        string name,
        string str,
        string[] words,
        int[] want
    )
    {
        List<int> got = WordConcat.FindWordConcatenation(str, words);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
