#include "treebfs/shared.h"

// Given a root of the binary tree and an integer key,
// find the level order successor of the node containing the given key as a
// value in the tree.
// The level order successor is the node that appears right after the given node
// in the level order traversal.
//
// Example 1
// Input: root = [1, 2, 3, 4, 5], key = 3
// Output: 4
// Explanation: The level-order traversal of the tree is [1, 2, 3, 4, 5]. The
// successor of 3 in this order is 4.
//
// Example 2
// Input: root = [12, 7, 1, 9, null, 10, 5], key = 9
// Output: 10
// Explanation: The level-order traversal of the tree is [12, 7, 1, 9, 10, 5].
// The successor of 9 in this order is 10.
//
// Example 3
// Input: root = [12, 7, 1, 9, null, 10, 5], key = 12
// Image
// Output: 7
// Explanation: The level-order traversal of the tree is [12, 7, 1, 9, 10]. The
// successor of 12 in this order is 7.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 105].
// -1000 <= Node.val <= 1000

TreeNode *find_successor
(
    TreeNode *root,
    int key
)
{
    if (root == NULL)
    {
        return NULL;
    }

    Queue queue = queue_new(sizeof(TreeNode *));
    node_queue_push(&queue, root);
    while (queue.len > 0)
    {
        // Get the front node of the queue
        TreeNode *current_node = node_queue_pop(&queue);

        // insert the children of current node in the queue
        if (current_node->left != NULL)
        {
            node_queue_push(&queue, current_node->left);
        }
        if (current_node->right != NULL)
        {
            node_queue_push(&queue, current_node->right);
        }

        // break if we have found the key
        if (current_node->val == key)
        {
            break;
        }
    }

    TreeNode *next_node = NULL;
    if (queue.len > 0)
    {
        // Get the front node of the queue
        next_node = *(TreeNode **)queue_front(&queue);
    }
    queue_free(&queue);
    return next_node;
}
