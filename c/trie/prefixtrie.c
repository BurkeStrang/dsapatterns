#include "trie/shared.h"

// Design and implement a Trie (also known as a Prefix Tree).
// A trie is a tree-like data structure that stores a dynamic set of strings,
// and is particularly useful for searching for words with a given prefix.
// Implement the Solution class:
// Solution() Initializes the object.
// void insert(word) Inserts word into the trie, making it available for future
// searches.
// bool search(word) Checks if the word exists in the trie.
// bool startsWith(word) Checks if any word in the trie starts with the given
// prefix.
//
// Example 1:
// Input:
// Trie operations: ["Trie", "insert", "search", "startsWith"]
// Arguments: [[], ["apple"], ["apple"], ["app"]]
// Expected Output: [-1, -1, 1, 1]
// Justification: After inserting "apple",
// "apple" exists in the Trie.
// There is also a word that starts with "app", which is "apple".
//
// Example 2:
// Input:
// Trie operations: ["Trie", "insert", "search", "startsWith", "search"]
// Arguments: [[], ["banana"], ["apple"], ["ban"], ["banana"]]
// Expected Output: [-1, -1, 0, 1, 1]
// Justification: After inserting "banana",
// "apple" does not exist in the Trie but a word that starts with "ban",
// which is "banana", does exist.
//
// Example 3:
// Input:
// Trie operations: ["Trie", "insert", "search", "startsWith", "startsWith"]
// Arguments: [[], ["grape"], ["grape"], ["grap"], ["gr"]]
// Expected Output: [-1, -1, 1, 1, 1]
// Justification: After inserting "grape",
// "grape" exists in the Trie.
// There are words that start with "grap" and "gr", which is "grape".
// Constraints:
// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 104 calls in total will be made to insert, search, and
// startsWith.

// Inserts a word into the trie.
void insert
(
    TrieNode *root,
    const char *word
)
{
    TrieNode *node = root;
    for (const char *c = word; *c != '\0'; c++)
    {
        int index = *c - 'a';
        if (node->children[index] == NULL)
        {
            node->children[index] = trie_node_new();
        }
        node = node->children[index];
    }
    node->is_end = true;
}

// Returns if the word is in the trie.
bool search
(
    const TrieNode *root,
    const char *word
)
{
    const TrieNode *node = root;
    for (const char *c = word; *c != '\0'; c++)
    {
        int index = *c - 'a';
        if (node->children[index] == NULL)
        {
            return false;
        }
        node = node->children[index];
    }
    return node->is_end;
}

// Returns if there is any word in the trie that starts with the given prefix.
bool starts_with
(
    const TrieNode *root,
    const char *prefix
)
{
    const TrieNode *node = root;
    for (const char *c = prefix; *c != '\0'; c++)
    {
        int index = *c - 'a';
        if (node->children[index] == NULL)
        {
            return false;
        }
        node = node->children[index];
    }
    return true;
}
