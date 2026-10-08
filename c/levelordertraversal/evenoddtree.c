#include "levelordertraversal/shared.h"

#include <stdbool.h>

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

bool is_even_odd_tree
(
    TreeNode *root
)
{
    if (root == NULL)
    {
        return true; // Check if the tree is empty
    }

    Queue queue = queue_new(sizeof(TreeNode *));
    node_queue_push(&queue, root);
    int level = 0; // Start with level 0
    bool valid = true;

    while (queue.len > 0 && valid)
    {
        int size = queue.len;
        IntList values = {0}; // List to store node values at current level

        for (int n = 0; n < size; n++)
        {
            // Get the next node in the queue and remove it from the queue
            TreeNode *node = node_queue_pop(&queue);
            intlist_push(&values, node->val);

            if (node->left != NULL)
            {
                // Add left child to the queue if it exists
                node_queue_push(&queue, node->left);
            }
            if (node->right != NULL)
            {
                // Add right child to the queue if it exists
                node_queue_push(&queue, node->right);
            }
        }

        // Check values for the current level
        for (int i = 0; i < values.len; i++)
        {
            int value = values.items[i];
            if (level % 2 == 0)
            {
                // Even level: values must be odd and strictly increasing
                if (value % 2 == 0 || (i > 0 && value <= values.items[i - 1]))
                {
                    valid = false;
                }
            }
            else
            {
                // Odd level: values must be even and strictly decreasing
                if (value % 2 != 0 || (i > 0 && value >= values.items[i - 1]))
                {
                    valid = false;
                }
            }
        }

        intlist_free(&values);
        level++; // Move to the next level
    }

    queue_free(&queue);
    return valid; // true if all levels satisfy the conditions
}
