#include "treedfs/shared.h"

#include <stdbool.h>

// Given a binary tree and a number sequence,
// find if the sequence is present as a root-to-leaf path in the given tree.

bool find_path_recursive
(
    TreeNode *current_node,
    const int *sequence,
    int sequence_len,
    int sequence_index
)
{
    if (current_node == NULL)
    {
        return false;
    }

    if (sequence_index >= sequence_len ||
        current_node->val != sequence[sequence_index])
    {
        return false;
    }

    // if the current node is a leaf, and it is the end of the sequence, we
    // have found a path!
    if (current_node->left == NULL && current_node->right == NULL &&
        sequence_index == sequence_len - 1)
    {
        return true;
    }

    // recursively call to traverse the left and right sub-tree
    // return true if any of the two recursive call return true
    return find_path_recursive(current_node->left, sequence, sequence_len,
                               sequence_index + 1) ||
           find_path_recursive(current_node->right, sequence, sequence_len,
                               sequence_index + 1);
}

bool find_path
(
    TreeNode *root,
    const int *sequence,
    int sequence_len
)
{
    if (root == NULL)
    {
        return sequence_len == 0;
    }

    return find_path_recursive(root, sequence, sequence_len, 0);
}
