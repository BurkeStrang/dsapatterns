use super::shared::TreeNode;

// Find the path with the maximum sum in a given binary tree.
// Write a function that returns the maximum sum.
// A path can be defined as a sequence of nodes between any two nodes and
// doesn’t necessarily pass through the root.
// The path must contain at least one node.

// Constraints:
// The number of nodes in the tree is in the range [1, 3 * 10^4].
// -1000 <= Node.val <= 1000

// Solution struct

// find_maximum_path_sum starts the recursive process and returns the result
pub fn find_maximum_path_sum(root: &Option<Box<TreeNode>>) -> i32 {
    let mut global_maximum_sum = i32::MIN;
    find_maximum_path_sum_recursive(root, &mut global_maximum_sum);
    global_maximum_sum
}

// find_maximum_path_sum_recursive calculates the maximum path sum recursively
fn find_maximum_path_sum_recursive(
    current_node: &Option<Box<TreeNode>>,
    global_maximum_sum: &mut i32,
) -> i32 {
    let Some(node) = current_node else {
        return 0;
    };

    let max_path_sum_from_left =
        find_maximum_path_sum_recursive(&node.left, global_maximum_sum);
    let max_path_sum_from_right =
        find_maximum_path_sum_recursive(&node.right, global_maximum_sum);

    // ignore paths with negative sums
    let max_path_sum_from_left = max_path_sum_from_left.max(0);
    let max_path_sum_from_right = max_path_sum_from_right.max(0);

    // local maximum sum
    let local_maximum_sum =
        max_path_sum_from_left + max_path_sum_from_right + node.val;

    // update the global maximum sum
    *global_maximum_sum = (*global_maximum_sum).max(local_maximum_sum);

    // return the maximum sum of any path from the current node
    max_path_sum_from_left.max(max_path_sum_from_right) + node.val
}
