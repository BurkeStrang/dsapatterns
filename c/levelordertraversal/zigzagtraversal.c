#include "levelordertraversal/shared.h"

#include <stdbool.h>

// Example 1:
// input: root = [3,9,20,null,null,15,7]
// output: [[3],[20,9],[15,7]]

// The levels are returned in a matrix that the caller must free.
IntMatrix traverse_zig_zag
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
    bool left_to_right = true;
    while (queue.len > 0)
    {
        int level_size = queue.len;
        IntList current_level = {0};
        for (int n = 0; n < level_size; n++)
        {
            TreeNode *current_node = node_queue_pop(&queue);

            // add the node to the current level based on the traverse
            // direction
            if (left_to_right)
            {
                intlist_push(&current_level, current_node->val);
            }
            else
            {
                intlist_insert(&current_level, 0, current_node->val);
            }

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
        // reverse the traversal direction
        left_to_right = !left_to_right;
    }

    queue_free(&queue);
    return result;
}
