namespace DsaPatterns.SlidingWindow;

public class StringAnagramsTests
{
    public static TheoryData<string, string, string, int[]> Cases =>
        new()
        {
            { "Example 1", "ppqp", "pq", [1, 2] },
            { "Example 2", "abbcabc", "abc", [2, 3, 4] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindStringAnagrams(
        string name,
        string str,
        string pattern,
        int[] want
    )
    {
        List<int> got = StringAnagrams.FindStringAnagrams(str, pattern);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
