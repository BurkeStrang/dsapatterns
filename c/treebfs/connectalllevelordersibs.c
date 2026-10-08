#include "treebfs/shared.h"

// Given a root of the binary tree, connect each node with its level order
// successor.
// The last node of each level should point to the first node of the next level.
//
// Example 1
// Input: root = [1, 2, 3, 4, 5, 6, 7]
// Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null
// Explanation: The tree is traversed level by level using BFS.
// Each node is connected to its next node in level order traversal,
// including connections between levels. The last node (7) points to null.
//
// Example 2
// Input: root = [12, 7, 1, 9, null, 10, 5]
// Image
// Output: 12 -> 7 -> 1 -> 9 -> 10 -> 5 -> null
// Explanation: Each node is connected to its next node in level order
// traversal.
// The last node (5) points to null, completing the connection of all level
// order siblings.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 212 - 1].
// -1000 <= Node.val <= 1000

// connect method to link tree nodes

TreeNode *connect_all
(
    TreeNode *root
)
{
    if (root == NULL)
    {
        return root;
    }

    Queue queue = queue_new(sizeof(TreeNode *));
    node_queue_push(&queue, root);
    TreeNode *previous_node = NULL;
    while (queue.len > 0)
    {
        // Get the front node of the queue
        TreeNode *current_node = node_queue_pop(&queue);
        if (previous_node != NULL)
        {
            previous_node->next = current_node;
        }
        previous_node = current_node;

        // insert the children of current node in the queue
        if (current_node->left != NULL)
        {
            node_queue_push(&queue, current_node->left);
        }
        if (current_node->right != NULL)
        {
            node_queue_push(&queue, current_node->right);
        }
    }

    queue_free(&queue);
    return root;
}
