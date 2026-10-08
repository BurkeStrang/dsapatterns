namespace DsaPatterns.Trie;

public class IndexParisTests
{
    public static TheoryData<string, string, string[], int[][]> Cases =>
        new()
        {
            {
                "Test Case 1",
                "thestarsareout",
                ["star", "stars", "are"],
                [
                    [3, 6],
                    [3, 7],
                    [8, 10],
                ]
            },
            {
                "Test Case 2",
                "bluebirdskyscraper",
                ["blue", "bird", "sky"],
                [
                    [0, 3],
                    [4, 7],
                    [8, 10],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void IndexPairs(
        string name,
        string text,
        string[] words,
        int[][] want
    )
    {
        List<int[]> got = IndexParis.IndexPairs(text, words);

        Assert.True(
            Shared.Format2D(got) == Shared.Format2D(want),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }
}
