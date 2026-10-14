#include "trie/shared.hpp"

#include <memory>
#include <string>
#include <vector>

// Given a list of distinct strings products and a string searchWord.
// Determine a set of product suggestions after each character of the search
// word is typed.
// Every time a character is typed,
// return a list containing up to three product names from the products list
// that have the same prefix as the typed string.
// If there are more than 3 matching products,
// return 3 lexicographically smallest products.
// These product names should be returned in lexicographical (alphabetical)
// order.
//
// Example 1:
// Input: Products: ["apple", "apricot", "application"], searchWord: "app"
// Expected Output: [["apple", "apricot", "application"], ["apple", "apricot",
// "application"], ["apple", "application"]]
// Justification: For the perfix 'a', "apple", "apricot", and "application"
// match.
// For the prefix 'ap', "apple", "apricot", and "application" match. For the
// prefix 'app', "apple", and "application" match
//
// Example 2:
// Input: Products: ["king", "kingdom", "kit"], searchWord: "ki"
// Expected Output: [["king", "kingdom", "kit"], ["king", "kingdom", "kit"]]
// Justification: All products starting with "k" are "king", "kingdom", and
// "kit". The list remains the same for the 'ki' prefix.
//
// Example 3:
// Input: Products: ["fantasy", "fast", "festival"], searchWord: "farm"
// Expected Output: [["fantasy", "fast", "festival"], ["fantasy", "fast"], [],
// []]
// Justification: Initially, "fantasy", "fast", and "festival" match 'f'. Moving
// to 'fa', only "fantasy" and "fast" match. No product matches with "far", and
// "farm".
//
// Constraints:
// 1 <= products.length <= 1000
// 1 <= products[i].length <= 3000
// 1 <= sum(products[i].length) <= 2 * 104
// All the strings of products are unique.
// products[i] consists of lowercase English letters.
// 1 <= searchWord.length <= 1000
// searchWord consists of lowercase English letters.

// dfs collects the words under a node in alphabetical order, stopping at 3
void dfs(const TrieNode *node, std::string &word,
         std::vector<std::string> &list)
{
    if (list.size() == 3)
    {
        return;
    }
    if (node->is_end)
    {
        list.push_back(word);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        const TrieNode *child = node->children[index(ch)].get();
        if (child != nullptr)
        {
            word += ch;
            dfs(child, word, list);
            word.pop_back();
        }
    }
}

class Trie
{
  public:
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

    // Search for words starting with prefix
    std::vector<std::string> search_prefix(const std::string &prefix) const
    {
        const TrieNode *node = &root;
        std::vector<std::string> list;
        for (char ch : prefix)
        {
            node = node->children[index(ch)].get();
            if (node == nullptr)
            {
                return list;
            }
        }
        std::string word = prefix;
        dfs(node, word, list);
        return list;
    }

  private:
    TrieNode root;
};

std::vector<std::vector<std::string>>
suggested_products(const std::vector<std::string> &products,
                   const std::string &search_word)
{
    Trie trie;
    for (const std::string &product : products)
    {
        trie.insert(product);
    }

    std::vector<std::vector<std::string>> result;
    // search with one more letter of the search word each time
    for (std::size_t end = 1; end <= search_word.size(); end++)
    {
        result.push_back(trie.search_prefix(search_word.substr(0, end)));
    }
    return result;
}
