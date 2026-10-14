#include "common/tree.hpp"

#include <queue>
#include <vector>

// Given a binary tree, return true if it is an Even-Odd tree. Otherwise, return
// false.
// The Even-odd tree must follow below two rules:
//
// At every even-indexed level (starting from 0),
// all node values must be odd and arranged in strictly increasing order from
// left to right.
// At every odd-indexed level,
// all node values must be even and arranged in strictly decreasing order from
// left to right.
//
// Example 1
// Input:
//     1
//    / \
//   10  4
//  / \
// 3   7
// Expected Output: true
// Justification: The tree follows both conditions for each odd and even level.
// So, it is an odd-even tree.
//
// Example 2
// Input:
//
//     5
//    / \
//   9   3
//  /     \
// 12      8
// Expected Output: false
// Justification: Level 1 has Odd values 9 and 3 in decreasing order, but it
// should have even values. So, the tree is not an odd-even tree.
//
// Example 3
// Input:
//     7
//    / \
//   10  2
//  / \
// 12  8
// Expected Output: false
// Justification: At level 2 (even-indexed), the values are 12 and 8, which are
// even, but they should have odd values. So, the tree is not an odd-even tree.
//
// Constraints:
// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 10^6

bool is_even_odd_tree(TreeNode *root)
{
    if (root == nullptr)
    {
        return true; // Check if the tree is empty
    }

    std::queue<TreeNode *> queue;
    queue.push(root);
    int level = 0; // Start with level 0

    while (!queue.empty())
    {
        int size = std::ssize(queue);
        std::vector<int> values; // Node values at the current level

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = queue.front(); // Take the next node
            queue.pop();
            values.push_back(node->value);

            // Add the children to the queue if they exist
            if (node->left != nullptr)
            {
                queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                queue.push(node->right);
            }
        }

        // Check values for the current level
        for (int i = 0; i < std::ssize(values); i++)
        {
            if (level % 2 == 0)
            {
                // Even level: values must be odd and strictly increasing
                if (values[i] % 2 == 0 || (i > 0 && values[i] <= values[i - 1]))
                {
                    return false;
                }
            }
            else
            {
                // Odd level: values must be even and strictly decreasing
                if (values[i] % 2 != 0 || (i > 0 && values[i] >= values[i - 1]))
                {
                    return false;
                }
            }
        }

        level++; // Move to the next level
    }

    return true; // If all levels satisfy the conditions, return true
}
