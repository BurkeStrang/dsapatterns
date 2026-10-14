#include "common/tree.hpp"

#include <queue>

// Given a root of the binary tree, connect each node with its level order
// successor.
// The last node of each level should point to a null node.
//
// Example 1:
// Input: root = [1, 2, 3, 4, 5, 6, 7]
// Output:
// [1 -> null]
// [2 -> 3 -> null]
// [4 -> 5 -> 6 -> 7 -> null]
// Explanation:
// The tree is traversed level by level using BFS. Each node is connected to its
// next right node at the same level. The last node of each level points to
// null.
//
// Example 2:
// Input: root = [12, 7, 1, 9, null, 10, 5]
// Output:
// [12 -> null]
// [7 -> 1 -> null]
// [9 -> 10 -> 5 -> null]
// Explanation:
// The nodes are connected to their next right sibling at the same level. The
// last node of each level points to null.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 2^12 - 1].
// -1000 <= Node.val <= 1000

void connect(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    std::queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        TreeNode *previous_node = nullptr;
        int level_size = std::ssize(queue);
        // connect all nodes of this level
        for (int i = 0; i < level_size; i++)
        {
            TreeNode *current_node = queue.front();
            queue.pop();
            if (previous_node != nullptr)
            {
                previous_node->next = current_node;
            }
            previous_node = current_node;

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
}
