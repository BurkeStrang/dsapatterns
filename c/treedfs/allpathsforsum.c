#include "treedfs/shared.h"

// Given a binary tree and a number ‘S’,
// find all paths from root-to-leaf such that the sum of all the node values of
// each path equals ‘S’.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

// find_paths_recursive to find paths recursively
void find_paths_recursive
(
    TreeNode *current_node,
    int sum,
    IntList *current_path,
    IntMatrix *all_paths
)
{
    if (current_node == NULL)
    {
        return;
    }

    // add the current node to the path
    intlist_push(current_path, current_node->val);

    // if the current node is a leaf and its value is equal to sum, save the
    // current path
    if (current_node->val == sum && current_node->left == NULL &&
        current_node->right == NULL)
    {
        intmatrix_push(all_paths, intlist_copy(current_path));
    }
    else
    {
        // traverse the left sub-tree
        find_paths_recursive(current_node->left, sum - current_node->val,
                             current_path, all_paths);
        // traverse the right sub-tree
        find_paths_recursive(current_node->right, sum - current_node->val,
                             current_path, all_paths);
    }

    // remove the current node from the path to backtrack, we need to remove
    // the current node while we are going up the recursive call stack.
    intlist_pop(current_path);
}

// The paths are returned in a matrix that the caller must free.
IntMatrix find_paths
(
    TreeNode *root,
    int sum
)
{
    IntMatrix all_paths = {0};
    IntList current_path = {0};
    find_paths_recursive(root, sum, &current_path, &all_paths);
    intlist_free(&current_path);
    return all_paths;
}
