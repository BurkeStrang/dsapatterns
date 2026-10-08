namespace DsaPatterns.Trie;

public class SearchAddTests
{
    public static TheoryData<string, string[], string, bool> Cases =>
        new()
        {
            { "SearchNode 'c.t'", ["cat", "dog"], "c.t", true },
            { "SearchNode 'd..g'", ["cat", "dog"], "d..g", false },
            { "SearchNode 'h.llo'", ["hello"], "h.llo", true },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SearchNode(string name, string[] add, string word, bool want)
    {
        PrefixTrie trie = new();
        foreach (string w in add)
        {
            trie.AddWord(w);
        }

        bool got = trie.SearchNode(word);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
