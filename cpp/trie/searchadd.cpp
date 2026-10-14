#include "trie/shared.hpp"

#include <memory>
#include <string_view>

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

// search_in_node is a helper method to search a word in the trie node.
bool search_in_node(std::string_view word, const TrieNode *node)
{
    for (std::size_t i = 0; i < word.size(); i++)
    {
        char ch = word[i];
        if (ch == '.')
        {
            // If it's a wildcard, recursively search for all possible
            // characters.
            for (const std::unique_ptr<TrieNode> &child : node->children)
            {
                if (child != nullptr &&
                    search_in_node(word.substr(i + 1), child.get()))
                {
                    return true;
                }
            }
            return false;
        }

        node = node->children[index(ch)].get();
        if (node == nullptr)
        {
            return false;
        }
    }
    return node->is_end; // Return if we're at the end of a valid word.
}

class Trie
{
  public:
    // add_word adds a word into the trie structure.
    void add_word(std::string_view word)
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
        node->is_end = true; // Mark the end of the word.
    }

    // search_node searches a word, considering '.' as a wildcard.
    bool search_node(std::string_view word) const
    {
        return search_in_node(word, &root);
    }

  private:
    TrieNode root;
};
