#pragma once

#include <array>
#include <memory>

// TrieNode is one node of a trie of lowercase words. Each problem of this
// pattern builds the trie it needs out of these nodes.
struct TrieNode
{
    // One slot for each letter of the alphabet.
    std::array<std::unique_ptr<TrieNode>, 26> children;
    // Flag to represent if the node is the end of a word.
    bool is_end = false;
};

// index returns the slot of a lowercase letter in TrieNode::children.
inline int index(char letter)
{
    return letter - 'a';
}
