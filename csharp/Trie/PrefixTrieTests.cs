namespace DsaPatterns.Trie;

public class PrefixTrieTests
{
    public static TheoryData<string, string, bool> SearchCases =>
        new()
        {
            { "Search 'grape'", "grape", true },
            { "Search 'grapefruit'", "grapefruit", true },
        };

    public static TheoryData<string, string, string, bool> StartsWithCases =>
        new()
        {
            { "StartsWith 'grap'", "grap", "grape", true },
            { "StartsWith 'gr'", "gr", "grape", true },
            { "StartsWith 'gra'", "gra", "grape", true },
        };

    [Theory]
    [MemberData(nameof(SearchCases))]
    public void Search(string name, string word, bool want)
    {
        PrefixTrie trie = new();
        trie.Insert(word);

        bool got = trie.Search(word);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }

    [Theory]
    [MemberData(nameof(StartsWithCases))]
    public void StartsWith(string name, string prefix, string word, bool want)
    {
        PrefixTrie trie = new();
        trie.Insert(word);

        bool got = trie.StartsWith(prefix);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
