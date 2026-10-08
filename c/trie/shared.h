// Shared types and helpers for the trie problems.
#ifndef DSAPATTERNS_TRIE_SHARED_H
#define DSAPATTERNS_TRIE_SHARED_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct TrieNode
{
    struct TrieNode *children[26]; // Represents each letter of the alphabet.
    bool is_end; // Flag to represent if the node is the end of a word.
} TrieNode;

// trie_node_new makes an empty node. A whole trie is just its root node.
static inline TrieNode *trie_node_new(void)
{
    return calloc(1, sizeof(TrieNode));
}

// trie_free frees a node and everything below it.
static inline void trie_free
(
    TrieNode *node
)
{
    if (node == NULL)
    {
        return;
    }
    for (int i = 0; i < 26; i++)
    {
        trie_free(node->children[i]);
    }
    free(node);
}

// trie_insert adds a word to the trie. It is the helper used by the problems
// that need a filled trie but aren't about building one.
static inline void trie_insert
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

#endif
