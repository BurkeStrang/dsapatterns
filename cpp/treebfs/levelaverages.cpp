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

std::vector<double> level_average(TreeNode *root)
{
    std::vector<double> result;
    if (root == nullptr)
    {
        return result;
    }

    std::queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        int level_size = std::ssize(queue);
        double level_sum = 0;
        for (int i = 0; i < level_size; i++)
        {
            TreeNode *current_node = queue.front();
            queue.pop();
            // add the node's value to the running sum
            level_sum += current_node->value;
            // insert the children of current node to the queue
            if (current_node->left != nullptr)
            {
                queue.push(current_node->left);
            }
            if (current_node->right != nullptr)
            {
                queue.push(current_node->right);
            }
        }
        // append the current level's average to the result array
        result.push_back(level_sum / level_size);
    }
    return result;
}
