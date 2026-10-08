#include "treebfs/shared.h"

// Given a binary tree,Given a binary tree, populate an array to represent its
// level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.
// populate an array to represent its level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.

// The averages are returned in a new array that the caller must free, and
// its length is stored in result_len.
double *level_average
(
    TreeNode *root,
    int *result_len
)
{
    double *result = NULL;
    int result_cap = 0;
    *result_len = 0;
    if (root == NULL)
    {
        return result;
    }

    Queue queue = queue_new(sizeof(TreeNode *));
    node_queue_push(&queue, root);
    while (queue.len > 0)
    {
        int level_size = queue.len;
        double level_sum = 0.0;
        for (int n = 0; n < level_size; n++)
        {
            TreeNode *current_node = node_queue_pop(&queue);
            // add the node's value to the running sum
            level_sum += current_node->val;
            // insert the children of current node to the queue
            if (current_node->left != NULL)
            {
                node_queue_push(&queue, current_node->left);
            }
            if (current_node->right != NULL)
            {
                node_queue_push(&queue, current_node->right);
            }
        }
        // append the current level's average to the result array
        if (*result_len == result_cap)
        {
            result_cap = result_cap == 0 ? 8 : result_cap * 2;
            result = realloc(result, (size_t)result_cap * sizeof(double));
        }
        result[(*result_len)++] = level_sum / level_size;
    }

    queue_free(&queue);
    return result;
}
