#include "common/tree.hpp"

#include <vector>

// Given a binary tree and a number ‘S’,
// find all paths from root-to-leaf such that the sum of all the node values of
// each path equals ‘S’.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

// find_paths_recursive to find paths recursively
void find_paths_recursive(TreeNode *current_node, int sum,
                          std::vector<int> &current_path,
                          std::vector<std::vector<int>> &all_paths)
{
    if (current_node == nullptr)
    {
        return;
    }

    // add the current node to the path
    current_path.push_back(current_node->value);

    if (current_node->value == sum && current_node->left == nullptr &&
        current_node->right == nullptr)
    {
        // if the current node is a leaf and its value is equal to sum, save
        // the current path
        all_paths.push_back(current_path);
    }
    else
    {
        // traverse the left sub-tree
        find_paths_recursive(current_node->left, sum - current_node->value,
                             current_path, all_paths);
        // traverse the right sub-tree
        find_paths_recursive(current_node->right, sum - current_node->value,
                             current_path, all_paths);
    }

    // remove the current node from the path to backtrack, we need to remove
    // the current node while we are going up the recursive call stack
    current_path.pop_back();
}

std::vector<std::vector<int>> find_paths(TreeNode *root, int sum)
{
    std::vector<std::vector<int>> all_paths;
    std::vector<int> current_path;
    find_paths_recursive(root, sum, current_path, all_paths);
    return all_paths;
}
