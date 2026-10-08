#include "treedfs/shared.h"

// Given a binary tree, find the length of its diameter.
// The diameter of a tree is the number of nodes on the longest path between any
// two leaf nodes.
// The diameter of a tree may or may not pass through the root.
// Note: You can always assume that there are at least two leaf nodes in the
// given tree.
//
// Constraints:
// n == edges.length + 1
// 1 <= n <= 104
// 0 <= ai, bi < n
// ai != bi

int calculate_height
(
    TreeNode *current_node,
    int *tree_diameter
)
{
    if (current_node == NULL)
    {
        return 0;
    }

    int left_tree_height = calculate_height(current_node->left, tree_diameter);
    int right_tree_height =
        calculate_height(current_node->right, tree_diameter);

    // if the current node doesn't have a left or right subtree, we can't have
    // a path passing through it, since we need a leaf node on each side
    if (left_tree_height != 0 && right_tree_height != 0)
    {
        // diameter at the current node will be equal to the height of left
        // subtree + the height of right sub-trees + '1' for the current node
        int diameter = left_tree_height + right_tree_height + 1;

        // update the global tree diameter
        if (diameter > *tree_diameter)
        {
            *tree_diameter = diameter;
        }
    }

    // height of the current node will be equal to the maximum of the heights
    // of left or right subtrees plus '1' for the current node
    int taller = left_tree_height > right_tree_height ? left_tree_height
                                                      : right_tree_height;
    return taller + 1;
}

int find_diameter
(
    TreeNode *root
)
{
    int tree_diameter = 0;
    calculate_height(root, &tree_diameter);
    return tree_diameter;
}
