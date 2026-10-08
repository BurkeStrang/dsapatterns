namespace DsaPatterns.Trie;

// Design a data structure that supports the addition of new words and the
// ability to check if a string matches any previously added word.
// Implement the Solution class:
//
// Solution() Initializes the object.
// void addWord(word) Inserts word into the data structure, making it available
// for future searches.
// bool search(word) Checks if there is any word in the data structure that
// matches word. The method returns true if such a match exists, otherwise
// returns false.
// Note: In the search query word, the character '.' can represent any single
// letter, effectively serving as a wildcard character.
//
// Examples
// Example 1:
//
// Input:
// ["Solution", "addWord", "addWord", "search", "search"]
// [[], ["apple"], ["banana"], ["apple"], ["......"]]
// Expected Output:
// [-1, -1, -1, 1, 1]
// Justification: After adding the words "apple" and "banana", searching for
// "apple" will return true since "apple" is in the data structure. Searching
// for "......" will also return true as "banana" match the pattern.
// Example 2:
//
// Input:
// ["Solution", "addWord", "addWord", "search", "search"]
// [[], ["cat"], ["dog"], ["c.t"], ["d..g"]]
// Expected Output:
// [-1, -1, -1, 1, 0]
// Justification: "c.t" matches "cat" and "d..g" doesn't matches "dog".
// Example 3:
//
// Input:
// ["Solution", "addWord", "search", "search"]
// [[], ["hello"], ["h.llo"], ["h...o"]]
// Expected Output:
// [-1, -1, 1, 1]
// Justification: "h.llo" and "h...o" both match "hello".
// Constraints:
//
// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 2 dots in word for search queries.
// At most 104 calls will be made to addWord and search.

// AddWord adds a word into the trie structure.

internal partial class PrefixTrie
{
    internal void AddWord(string word)
    {
        TrieNode node = root;
        foreach (char c in word)
        {
            int index = c - 'a';
            // If the child node doesn't exist, create it.
            node.Children[index] ??= new TrieNode();
            node = node.Children[index]!; // Move to the child node.
        }

        node.IsEnd = true; // Mark the end of the word.
    }

    // SearchNode searches a word, considering '.' as a wildcard.
    internal bool SearchNode(string word)
    {
        return SearchInNode(word, root);
    }

    // SearchInNode is a helper method to search a word in the trie node.
    private static bool SearchInNode(string word, TrieNode node)
    {
        for (int i = 0; i < word.Length; i++)
        {
            char ch = word[i];
            if (ch == '.')
            {
                // If it's a wildcard, recursively search for all possible
                // characters.
                foreach (TrieNode? child in node.Children)
                {
                    if (child != null && SearchInNode(word[(i + 1)..], child))
                    {
                        return true;
                    }
                }

                return false;
            }

            TrieNode? next = node.Children[ch - 'a'];
            if (next == null)
            {
                return false;
            }

            node = next; // Move to the next node.
        }

        return node.IsEnd; // Return if we're at the end of a valid word.
    }
}
