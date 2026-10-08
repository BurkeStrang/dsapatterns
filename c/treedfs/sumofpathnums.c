#include "treedfs/shared.h"

// Given a binary tree where each node can only have a digit (0-9) value,
// each root-to-leaf path will represent a number.
// Find the total sum of all the numbers represented by all paths.

int find_path_sum
(
    TreeNode *node,
    int current_sum
)
{
    if (node == NULL)
    {
        return 0;
    }

    // calculate the path number for the current node
    current_sum = current_sum * 10 + node->val;

    // if it's a leaf node, return the current path sum
    if (node->left == NULL && node->right == NULL)
    {
        return current_sum;
    }

    // traverse left and right subtrees
    return find_path_sum(node->left, current_sum) +
           find_path_sum(node->right, current_sum);
}

int find_sum_of_path_numbers
(
    TreeNode *root
)
{
    return find_path_sum(root, 0);
}
