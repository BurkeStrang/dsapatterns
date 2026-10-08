#include "common/map.h"
#include "treedfs/shared.h"

// Given a binary tree and a number ‘S’,
// find all paths in the tree such that the sum of all the node values of each
// path equals ‘S’.
// Please note that the paths can start or end at
// any node but all paths must follow direction from parent to child (top to
// bottom).

int count_paths_prefix_sum
(
    TreeNode *node,
    int target_sum,
    IntMap *map,
    int current_path_sum
)
{
    if (node == NULL)
    {
        return 0;
    }

    // The number of paths that have the required sum.
    int path_count = 0;

    // 'current_path_sum' is the prefix sum, i.e., sum of all node values from
    // the root to the current node.
    current_path_sum += node->val;

    // This is the base case. If the current sum is equal to the target sum,
    // we have found a path from root to the current node having the required
    // sum. Hence, we increment the path count by 1.
    if (target_sum == current_path_sum)
    {
        path_count++;
    }

    // 'current_path_sum' is the path sum from root to the current node. If
    // within this path, there is a valid solution, then there must be an
    // 'old_path_sum' such that:
    // => current_path_sum - old_path_sum = target_sum
    // => current_path_sum - target_sum = old_path_sum
    // Hence, we can search such an 'old_path_sum' in the map from the key
    // 'current_path_sum - target_sum'.
    path_count += intmap_get(map, current_path_sum - target_sum);

    // This is the key step in the algorithm. We are storing the number of
    // times the prefix sum `current_path_sum` has occurred so far.
    intmap_add(map, current_path_sum, 1);

    // Counting the number of paths from the left and right subtrees.
    path_count +=
        count_paths_prefix_sum(node->left, target_sum, map, current_path_sum);
    path_count +=
        count_paths_prefix_sum(node->right, target_sum, map, current_path_sum);

    // Removing the current path sum from the map for backtracking.
    // 'current_path_sum' is the prefix sum up to the current node. When we go
    // back (i.e., backtrack), then the current node is no more a part of the
    // path, hence, we should remove its prefix sum from the map.
    intmap_add(map, current_path_sum, -1);

    return path_count;
}

int count_paths
(
    TreeNode *root,
    int target_sum
)
{
    // A map that stores the number of times a prefix sum has occurred so far.
    IntMap map = {0};
    int count = count_paths_prefix_sum(root, target_sum, &map, 0);
    intmap_free(&map);
    return count;
}
