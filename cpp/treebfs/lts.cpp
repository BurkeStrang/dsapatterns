#include "common/tree.hpp"

#include <queue>
#include <vector>

// Given a binary tree,Given a binary tree, populate an array to represent its
// level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.
// populate an array to represent its level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.

std::vector<std::vector<int>> traverse_basic(TreeNode *root)
{
    std::vector<std::vector<int>> result;
    if (root == nullptr)
    {
        return result;
    }

    std::queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        int level_size = std::ssize(queue);
        std::vector<int> current_level;
        for (int i = 0; i < level_size; i++)
        {
            TreeNode *current_node = queue.front();
            queue.pop();
            // add the node to the current level
            current_level.push_back(current_node->value);
            // insert the children of current node in the queue
            if (current_node->left != nullptr)
            {
                queue.push(current_node->left);
            }
            if (current_node->right != nullptr)
            {
                queue.push(current_node->right);
            }
        }
        result.push_back(current_level);
    }
    return result;
}
