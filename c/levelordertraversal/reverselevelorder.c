#include "levelordertraversal/shared.h"

// Given the root of a binary tree, return the bottom-up level order traversal
// of its nodes' values.
// (i.e., the lowest level comes first in left to right order.)
//
// Example 1
// Input: root = [1, 2, 3, 4, 5, 6, 7]
// Image
// Expected Output: [[4, 5, 6, 7], [2, 3], [1]]
// Justification:
// The third level has 4, 5, 6, and 7 nodes.
// The second level has 2 and 3 nodes.
// The first level has a single node with the value 1.
//
// Example 2
// Input: root = [12, 7, 1, null, 9, 10, 5]
// Image
// Expected Output: [[9, 10, 5], [7, 1], [12]]
// Justification:
// The third level has 9, 10, and 5 nodes.
// The second level has 7 and 1 nodes.
// The first level has a single node with the value 12.
//
// Example 3
// Input: root = [6,5,2,null,null,1,6,3,56,3]
// Image
// Expected Output: [[3,56,3],[1,6],[5,2],[6]]
// Justification:
// The fourth level has 3, 56, and 3 nodes.
// The third level has 1, and 6 nodes.
// The second level has 5 and 2 nodes.
// The first level has a single node with the value 6.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

// The levels are returned in a matrix that the caller must free.
IntMatrix traverse
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
        // append the current level at the beginning
        intmatrix_insert(&result, 0, current_level);
    }

    queue_free(&queue);
    return result;
}
