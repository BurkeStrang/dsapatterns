#include "common/tree.hpp"

#include <vector>

// Given a binary tree and a number sequence,
// find if the sequence is present as a root-to-leaf path in the given tree.

bool find_path_recursive(TreeNode *current_node,
                         const std::vector<int> &sequence, int sequence_index)
{
    if (current_node == nullptr)
    {
        return false;
    }

    int sequence_length = std::ssize(sequence);
    if (sequence_index >= sequence_length ||
        current_node->value != sequence[sequence_index])
    {
        return false;
    }

    // if the current node is a leaf, and it is the end of the sequence, we
    // have found a path!
    if (current_node->left == nullptr && current_node->right == nullptr &&
        sequence_index == sequence_length - 1)
    {
        return true;
    }

    // recursively call to traverse the left and right sub-tree
    // return true if any of the two recursive call return true
    return find_path_recursive(current_node->left, sequence,
                               sequence_index + 1) ||
           find_path_recursive(current_node->right, sequence,
                               sequence_index + 1);
}

bool find_path(TreeNode *root, const std::vector<int> &sequence)
{
    if (root == nullptr)
    {
        return sequence.empty();
    }

    return find_path_recursive(root, sequence, 0);
}
