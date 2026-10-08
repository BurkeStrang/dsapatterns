#include "treedfs/shared.h"

// Find the path with the maximum sum in a given binary tree.
// Write a function that returns the maximum sum.
// A path can be defined as a sequence of nodes between any two nodes and
// doesn’t necessarily pass through the root.
// The path must contain at least one node.

// Constraints:
// The number of nodes in the tree is in the range [1, 3 * 10^4].
// -1000 <= Node.val <= 1000

// Solution struct

// find_maximum_path_sum_recursive calculates the maximum path sum
// recursively, keeping the best sum seen so far in *global_maximum_sum
int find_maximum_path_sum_recursive
(
    TreeNode *current_node,
    int *global_maximum_sum
)
{
    if (current_node == NULL)
    {
        return 0;
    }

    int max_path_sum_from_left =
        find_maximum_path_sum_recursive(current_node->left, global_maximum_sum);
    int max_path_sum_from_right = find_maximum_path_sum_recursive(
        current_node->right, global_maximum_sum);

    // ignore paths with negative sums
    if (max_path_sum_from_left < 0)
    {
        max_path_sum_from_left = 0;
    }
    if (max_path_sum_from_right < 0)
    {
        max_path_sum_from_right = 0;
    }

    // local maximum sum
    int local_maximum_sum =
        max_path_sum_from_left + max_path_sum_from_right + current_node->val;

    // update the global maximum sum
    if (local_maximum_sum > *global_maximum_sum)
    {
        *global_maximum_sum = local_maximum_sum;
    }

    // return the maximum sum of any path from the current node
    int best_side = max_path_sum_from_left > max_path_sum_from_right
                        ? max_path_sum_from_left
                        : max_path_sum_from_right;
    return best_side + current_node->val;
}

// find_maximum_path_sum starts the recursive process and returns the result
int find_maximum_path_sum
(
    TreeNode *root
)
{
    int global_maximum_sum = INT_MIN;
    find_maximum_path_sum_recursive(root, &global_maximum_sum);
    return global_maximum_sum;
}
