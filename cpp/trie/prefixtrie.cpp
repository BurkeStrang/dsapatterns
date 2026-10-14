#include "trie/shared.hpp"

#include <memory>
#include <string>

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

class Trie
{
  public:
    // Inserts a word into the trie.
    void insert(const std::string &word)
    {
        TrieNode *node = &root;
        for (char c : word)
        {
            std::unique_ptr<TrieNode> &child = node->children[index(c)];
            // If the child node doesn't exist, create it, then move to it.
            if (child == nullptr)
            {
                child = std::make_unique<TrieNode>();
            }
            node = child.get();
        }
        node->is_end = true;
    }

    // Returns if the word is in the trie.
    bool search(const std::string &word) const
    {
        const TrieNode *node = &root;
        for (char c : word)
        {
            node = node->children[index(c)].get();
            if (node == nullptr)
            {
                return false;
            }
        }
        return node->is_end;
    }

    // Returns if there is any word in the trie that starts with the given
    // prefix.
    bool starts_with(const std::string &prefix) const
    {
        const TrieNode *node = &root;
        for (char c : prefix)
        {
            node = node->children[index(c)].get();
            if (node == nullptr)
            {
                return false;
            }
        }
        return true;
    }

  private:
    TrieNode root;
};
