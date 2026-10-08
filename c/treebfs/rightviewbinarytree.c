#include "treebfs/shared.h"

// Given a root of the binary tree, return an array containing nodes in its
// right view.
// The right view of a binary tree consists of nodes that are visible when the
// tree is viewed from the right side.
// For each level of the tree, the last node encountered in that level will be
// included in the right view.
//
// Example 1
// Input: root = [1, 2, 3, 4, 5, 6, 7]
// Expected Output: [1, 3, 7]
// Justification:
// The last node at level 0 is 1.
// The last node at level 1 is 3.
// The last node at level 2 is 7.
//
// Example 2
// Input: root = [12, 7, 1, null, 9, 10, 5, null, 3]
// Expected Output: [12, 1, 5, 3]
// Justification:
// The last node at level 0 is 12.
// The last node at level 1 is 1.
// The last node at level 2 is 5.
// The last node at level 3 is 3.
//
// Example 3
// Input: root = [8, 4, 9, 3, null, null, 10, 2]
// Expected Output: [8, 9, 10, 2]
// Justification:
// The last node at level 0 is 8.
// The last node at level 1 is 9.
// The last node at level 2 is 10.
// The last node at level 3 is 2.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

// The right view is returned in a list that the caller must free.
IntList right_view
(
    TreeNode *root
)
{
    IntList result = {0};
    if (root == NULL)
    {
        return result;
    }

    Queue queue = queue_new(sizeof(TreeNode *));
    node_queue_push(&queue, root);

    while (queue.len > 0)
    {
        int level_size = queue.len;
        TreeNode *current_node = NULL;

        for (int n = 0; n < level_size; n++)
        {
            current_node = node_queue_pop(&queue);

            if (current_node->left != NULL)
            {
                node_queue_push(&queue, current_node->left);
            }
            if (current_node->right != NULL)
            {
                node_queue_push(&queue, current_node->right);
            }
        }

        // Add the rightmost node of this level
        intlist_push(&result, current_node->val);
    }

    queue_free(&queue);
    return result;
}
