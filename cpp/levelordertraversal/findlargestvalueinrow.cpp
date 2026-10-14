#include "common/tree.hpp"

#include <algorithm>
#include <climits>
#include <queue>
#include <vector>

// Given the root of a binary tree, return an array containing the largest value
// in each row of the tree (0-indexed).
//
// Examples
// Example 1
// Input: root = [1, 2, 3, 4, 5, null, 6]
// Expected Output: [1, 3, 6]
// Image
// Justification:
// The first row contains 1. The largest value is 1.
// The second row has 2 and 3, and the largest is 3.
// The third row has 4, 5, and 6, and the largest is 6.
// Example 2
// Input: root = [7, 4, 8, 2, 5, null, 9, null, 3]
// Expected Output: [7, 8, 9, 3]
// Image
// Justification:
// The first row contains 7, and the largest value is 7.
// The second row has 4 and 8, and the largest is 8.
// The third row has 2, 5, and 9, and the largest is 9.
// The fourth row has 3, and the largest is 3.
// Example 3
// Input: root = [10, 5]
// Expected Output: [10, 5]
// Justification:
// The first row has 10, and the largest value is 10.
// The second row contains 5, and the largest is 5.
// Constraints:
//
// The number of nodes in the tree will be in the range [0, 104].
// -231 <= Node.val <= 231 - 1

std::vector<int> largest_values(TreeNode *root)
{
    std::vector<int> result;

    // Return an empty list if the root is null
    if (root == nullptr)
    {
        return result;
    }

    // Initialize a queue for level order traversal
    std::queue<TreeNode *> queue;
    queue.push(root);

    // Perform level order traversal
    while (!queue.empty())
    {
        int level_size = std::ssize(queue);
        int max_val = INT_MIN;

        // Traverse all nodes at the current level
        for (int i = 0; i < level_size; i++)
        {
            TreeNode *node = queue.front();
            queue.pop();

            // Find the maximum value at the current level
            max_val = std::max(max_val, node->value);

            // Add left and right children to the queue for the next level
            if (node->left != nullptr)
            {
                queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                queue.push(node->right);
            }
        }

        // Store the largest value of the current level
        result.push_back(max_val);
    }

    return result;
}
