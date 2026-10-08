#include "treebfs/shared.h"

#include <stdbool.h>

// Given a root of the binary tree, find the minimum depth of a binary tree.
// The minimum depth is the number of nodes along the shortest path from the
// root node to the nearest leaf node.
//
// Example 1
// Input: [1,2,3,4,5]
// Output: 2
//
// Example 2
// Input: [1,2]
// Output: 2
//
// Example 3
// Input: [1,2,3,4,5,6]
// Output: 3
//
// Example 4
// Input: [1]
// Output: 1
//
// Constraints:
// The number of nodes in the tree is in the range [0, 10^5].
// -1000 <= Node.val <= 1000

int find_depth
(
    TreeNode *root
)
{
    if (root == NULL)
    {
        return 0;
    }

    Queue queue = queue_new(sizeof(TreeNode *));
    node_queue_push(&queue, root);
    int minimum_tree_depth = 0;
    bool found_leaf = false;
    while (queue.len > 0 && !found_leaf)
    {
        minimum_tree_depth++;
        int level_size = queue.len;
        for (int n = 0; n < level_size; n++)
        {
            TreeNode *current_node = node_queue_pop(&queue);

            // check if this is a leaf node
            if (current_node->left == NULL && current_node->right == NULL)
            {
                found_leaf = true;
                break;
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
    }

    queue_free(&queue);
    return minimum_tree_depth;
}
