#include "treebfs/shared.h"

// Given a binary tree,Given a binary tree, populate an array to represent its
// level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.
// populate an array to represent its level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.

// The levels are returned in a matrix that the caller must free.
IntMatrix traverse_basic
(
    TreeNode *root
)
{
    IntMatrix result = {0};
    if (root == NULL)
    {
        return result;
    }

    Queue queue = queue_new(sizeof(TreeNode *));
    node_queue_push(&queue, root);
    while (queue.len > 0)
    {
        int level_size = queue.len;
        IntList current_level = {0};
        for (int n = 0; n < level_size; n++)
        {
            TreeNode *current_node = node_queue_pop(&queue);
            // add the node to the current level
            intlist_push(&current_level, current_node->val);
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
        intmatrix_push(&result, current_level);
    }

    queue_free(&queue);
    return result;
}
