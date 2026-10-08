namespace DsaPatterns.Trie;

internal class TrieNode
{
    // Represents each letter of the alphabet.
    public TrieNode?[] Children { get; } = new TrieNode?[26];

    // Flag to represent if the node is the end of a word.
    public bool IsEnd { get; set; }
}

// Shared helpers for the trie problems.
internal static class Shared
{
    internal static string Format<T>(IEnumerable<T> items)
    {
        return $"[{string.Join(", ", items)}]";
    }

    internal static string Format2D<T>(IEnumerable<IEnumerable<T>> rows)
    {
        return $"[{string.Join(", ", rows.Select(Format))}]";
    }
}
