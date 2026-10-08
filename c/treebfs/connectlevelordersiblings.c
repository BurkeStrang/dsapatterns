#include "treebfs/shared.h"

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

TreeNode *connect
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
    while (queue.len > 0)
    {
        TreeNode *previous_node = NULL;
        int level_size = queue.len;
        // connect all nodes of this level
        for (int n = 0; n < level_size; n++)
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
    }

    queue_free(&queue);
    return root;
}
