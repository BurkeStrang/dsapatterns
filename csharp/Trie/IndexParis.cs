namespace DsaPatterns.Trie;

// Given a string text and a list of strings words, identify all [i, j]
// index pairs such that the substring text[i...j] is in words.
// These index pairs should be returned in ascending order,
// first by the start index, then by the end index.
// Find every occurrence of each word within the text,
// ensuring that overlapping occurrences are also identified.
//
// Example 1
// Input: text = "bluebirdskyscraper", words = ["blue", "bird", "sky"]
// Expected Output: [[0, 3], [4, 7], [8, 10]]
// Justification: The word "blue" is found from index 0 to 3, "bird" from 4 to
// 7, and "sky" from 8 to 10 in the string.
//
// Example 2
// Input: text = "programmingisfun", words = ["pro", "is", "fun", "gram"]
// Expected Output: [[0, 2], [3, 6], [11, 12], [13, 15]]
// Justification: "pro" is found from 0 to 2, "gram" from 3 to 6, "is" from 11
// to 12, and "fun" from 13 to 15.
//
// Example 3
// Input: text = "interstellar", words = ["stellar", "star", "inter"]
// Expected Output: [[0, 4], [5, 11]]
// Justification: "inter" is found from 0 to 4, and "stellar" from 5 to 11.
// "star" is not found.
//
// Constraints:
// 1 <= text.length <= 100
// 1 <= words.length <= 20
// 1 <= words[i].length <= 50
// text and words[i] consist of lowercase English letters.
// All the strings of words are unique.

internal partial class Trie
{
    internal TrieNode Root { get; } = new();

    // Insert inserts a word into the trie
    internal void Insert(string word)
    {
        TrieNode node = Root;
        foreach (char c in word)
        {
            int index = c - 'a';
            node.Children[index] ??= new TrieNode();
            node = node.Children[index]!;
        }

        node.IsEnd = true;
    }
}

internal static class IndexParis
{
    // IndexPairs finds all index pairs of substrings in the text that match
    // any word in the trie
    internal static List<int[]> IndexPairs(string text, string[] words)
    {
        Trie trie = new();

        // Populate the trie with the given words
        foreach (string word in words)
        {
            trie.Insert(word);
        }

        List<int[]> result = [];
        for (int i = 0; i < text.Length; i++)
        {
            TrieNode node = trie.Root;
            // Iterate through the text to find matching words in the trie
            for (int j = i; j < text.Length; j++)
            {
                TrieNode? next = node.Children[text[j] - 'a'];
                if (next == null)
                {
                    break; // No matching character in trie
                }

                node = next;
                if (node.IsEnd)
                {
                    result.Add([i, j]); // Append the index pair if word found
                }
            }
        }

        return result;
    }
}
