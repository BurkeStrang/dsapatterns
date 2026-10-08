#include "levelordertraversal/shared.h"

// You are given the root of a binary tree. The level of its root node is 1,
// the level of its children is 2, and so on.
// Return the level x where the sum of the values of all nodes is the highest.
// If there are multiple levels with the same maximum sum, return the smallest
// level number x.
//
// Example 1:
// Input: root = [1, 20, 3, 4, 5, null, 8]
// Image
// Expected Output: 2
// Explanation:
// Level 1 has nodes: [1] with sum = 1
// Level 2 has nodes: [20, 3] with sum = 20 + 3 = 23
// Level 3 has nodes: [4, 5, 8] with sum = 4 + 5 + 8 = 17
// The maximum sum is 23 at level 2.
//
// Example 2:
// Input: root = [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]
// Image
// Expected Output: 3
// Explanation:
// Level 1 has nodes: [10] with sum = 10
// Level 2 has nodes: [5, -3] with sum = 5 - 3 = 2
// Level 3 has nodes: [3, 2, 11] with sum = 3 + 2 + 11 = 16
// Level 4 has nodes: [3, -2, 1] with sum = 3 - 2 + 1 = 2
// The maximum sum is 16 at level 3.
//
// Example 3:
// Input: root = [5, 6, 7, 8, null, null, 9, null, null, 10]
// Image
// Expected Output: 2
// Explanation:
// Level 1 has nodes: [5] with sum = 5
// Level 2 has nodes: [6, 7] with sum = 6 + 7 = 13
// Level 3 has nodes: [8, 9] with sum = 8 + 9 = 17
// Level 4 has nodes: [10] with sum = 10
// The maximum sum is 17 at level 3.
//
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105

int max_level_sum
(
    TreeNode *root
)
{
    if (root == NULL)
    {
        return 0;
    }

    Queue queue = queue_new(sizeof(TreeNode *));
    node_queue_push(&queue, root); // Add the root node to the queue

    int max_sum = INT_MIN;
    int result_level = 1;  // To keep track of the level with the maximum sum
    int current_level = 1; // Current level counter

    while (queue.len > 0)
    {
        int level_size = queue.len;
        int current_sum = 0; // To calculate the sum of nodes at this level

        for (int n = 0; n < level_size; n++)
        {
            TreeNode *node = node_queue_pop(&queue);

            current_sum += node->val; // Add the node's value to the sum

            // Add left child to the queue if it exists
            if (node->left != NULL)
            {
                node_queue_push(&queue, node->left);
            }

            // Add right child to the queue if it exists
            if (node->right != NULL)
            {
                node_queue_push(&queue, node->right);
            }
        }

        // If the current level sum is greater than the max_sum found so far
        if (current_sum > max_sum)
        {
            max_sum = current_sum;        // Update max_sum
            result_level = current_level; // Update to the current level
        }

        current_level++; // Increment the level counter
    }

    queue_free(&queue);
    return result_level;
}
