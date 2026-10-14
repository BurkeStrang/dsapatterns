use super::shared::TreeNode;

// Given a binary tree where each node can only have a digit (0-9) value,
// each root-to-leaf path will represent a number.
// Find the total sum of all the numbers represented by all paths.

pub fn find_sum_of_path_numbers(root: &Option<Box<TreeNode>>) -> i32 {
    find_path_sum(root, 0)
}

fn find_path_sum(node: &Option<Box<TreeNode>>, current_sum: i32) -> i32 {
    let Some(node) = node else {
        return 0;
    };

    // calculate the path number for the current node
    let current_sum = current_sum * 10 + node.val;

    // if it's a leaf node, return the current path sum
    if node.left.is_none() && node.right.is_none() {
        return current_sum;
    }

    // traverse left and right subtrees
    find_path_sum(&node.left, current_sum)
        + find_path_sum(&node.right, current_sum)
}
