namespace DsaPatterns.Trie;

public class SearchSuggestionSystemTests
{
    public static TheoryData<string, string[], string, string[][]> Cases =>
        new()
        {
            {
                "Test Case 1",
                ["mobile", "mouse", "moneypot", "monitor", "mousepad"],
                "mouse",
                [
                    ["mobile", "moneypot", "monitor"],
                    ["mobile", "moneypot", "monitor"],
                    ["mouse", "mousepad"],
                    ["mouse", "mousepad"],
                    ["mouse", "mousepad"],
                ]
            },
            {
                "Test Case 2",
                ["havana"],
                "havana",
                [
                    ["havana"],
                    ["havana"],
                    ["havana"],
                    ["havana"],
                    ["havana"],
                    ["havana"],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SuggestedProducts(
        string name,
        string[] products,
        string searchWord,
        string[][] want
    )
    {
        List<List<string>> got = SearchSuggestionSystem.SuggestedProducts(
            products,
            searchWord
        );

        Assert.True(
            Shared.Format2D(got) == Shared.Format2D(want),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }
}
