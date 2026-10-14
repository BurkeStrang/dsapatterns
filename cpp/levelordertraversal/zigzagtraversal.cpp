#include "common/tree.hpp"

#include <deque>
#include <queue>
#include <vector>

// Example 1:
// input: root = [3,9,20,null,null,15,7]
// output: [[3],[20,9],[15,7]]

std::vector<std::vector<int>> traverse_zig_zag(TreeNode *root)
{
    std::vector<std::vector<int>> result;
    if (root == nullptr)
    {
        return result;
    }

    std::queue<TreeNode *> queue;
    queue.push(root);
    bool left_to_right = true;
    while (!queue.empty())
    {
        int level_size = std::ssize(queue);
        std::deque<int> current_level;
        for (int i = 0; i < level_size; i++)
        {
            TreeNode *current_node = queue.front();
            queue.pop();

            // add the node to the current level based on the traverse
            // direction
            if (left_to_right)
            {
                current_level.push_back(current_node->value);
            }
            else
            {
                current_level.push_front(current_node->value);
            }

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
        result.emplace_back(current_level.begin(), current_level.end());
        // reverse the traversal direction
        left_to_right = !left_to_right;
    }

    return result;
}
