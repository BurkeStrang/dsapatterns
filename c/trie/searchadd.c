#include "trie/shared.h"

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

void add_word
(
    TrieNode *root,
    const char *word
)
{
    TrieNode *node = root;
    for (const char *c = word; *c != '\0'; c++)
    {
        int index = *c - 'a';
        // If the child node doesn't exist, create it.
        if (node->children[index] == NULL)
        {
            node->children[index] = trie_node_new();
        }
        node = node->children[index]; // Move to the child node.
    }
    node->is_end = true; // Mark the end of the word.
}

// search_in_node is a helper function to search a word in the trie node.
bool search_in_node
(
    const char *word,
    const TrieNode *node
)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        char ch = word[i];
        if (ch == '.')
        {
            // If it's a wildcard, recursively search for all possible
            // characters.
            for (int c = 0; c < 26; c++)
            {
                const TrieNode *child = node->children[c];
                if (child != NULL && search_in_node(word + i + 1, child))
                {
                    return true;
                }
            }
            return false;
        }

        int index = ch - 'a';
        if (node->children[index] == NULL)
        {
            return false;
        }
        node = node->children[index]; // Move to the next node.
    }
    return node->is_end; // Return if we're at the end of a valid word.
}

// search_node searches a word, considering '.' as a wildcard.
bool search_node
(
    const TrieNode *root,
    const char *word
)
{
    return search_in_node(word, root);
}
