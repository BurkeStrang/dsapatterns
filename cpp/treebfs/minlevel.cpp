#include "common/tree.hpp"

#include <queue>

// Given a root of the binary tree, find the minimum depth of a binary tree.
// The minimum depth is the number of nodes along the shortest path from the
// root node to the nearest leaf node.
//
// Example 1
// Input: [1,2,3,4,5]
// Output: 2
//
// Example 2
// Input: [1,2]
// Output: 2
//
// Example 3
// Input: [1,2,3,4,5,6]
// Output: 3
//
// Example 4
// Input: [1]
// Output: 1
//
// Constraints:
// The number of nodes in the tree is in the range [0, 10^5].
// -1000 <= Node.val <= 1000

int find_depth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    std::queue<TreeNode *> queue;
    queue.push(root);
    int minimum_tree_depth = 0;
    while (!queue.empty())
    {
        minimum_tree_depth++;
        int level_size = std::ssize(queue);
        for (int i = 0; i < level_size; i++)
        {
            TreeNode *current_node = queue.front();
            queue.pop();

            // check if this is a leaf node
            if (current_node->left == nullptr && current_node->right == nullptr)
            {
                return minimum_tree_depth;
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
    }
    return minimum_tree_depth;
}
