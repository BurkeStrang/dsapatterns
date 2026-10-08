#include "common/list.h"
#include "common/strbuf.h"
#include "trie/shared.h"

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

// DFS to find words starting with the given prefix

// word holds the letters on the path to node; it is restored before
// returning.
void dfs
(
    const TrieNode *node,
    StrBuf *word,
    StrList *list
)
{
    if (list->len == 3)
    {
        return;
    }
    if (node->is_end)
    {
        strlist_push(list, word->data);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (node->children[ch - 'a'] != NULL)
        {
            strbuf_push(word, ch);
            dfs(node->children[ch - 'a'], word, list);
            strbuf_pop(word);
        }
    }
}

// Search for words starting with prefix
StrList search
(
    const TrieNode *root,
    const char *prefix
)
{
    const TrieNode *node = root;
    StrList list = {0};
    for (const char *ch = prefix; *ch != '\0'; ch++)
    {
        if (node->children[*ch - 'a'] == NULL)
        {
            return list;
        }
        node = node->children[*ch - 'a'];
    }
    StrBuf word = {0};
    strbuf_append(&word, prefix);
    dfs(node, &word, &list);
    strbuf_free(&word);
    return list;
}

// The result has one list of suggestions per letter of search_word. The
// caller frees each list and then the array.
StrList *suggested_products
(
    const char *const *products,
    int products_len,
    const char *search_word
)
{
    TrieNode *root = trie_node_new();
    for (int i = 0; i < products_len; i++)
    {
        trie_insert(root, products[i]);
    }

    int search_len = (int)strlen(search_word);
    StrList *result = calloc((size_t)search_len + 1, sizeof(StrList));
    StrBuf prefix = {0};
    for (int i = 0; i < search_len; i++)
    {
        strbuf_push(&prefix, search_word[i]);
        result[i] = search(root, prefix.data);
    }

    strbuf_free(&prefix);
    trie_free(root);
    return result;
}
