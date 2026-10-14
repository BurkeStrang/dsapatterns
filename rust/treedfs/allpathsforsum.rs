use super::shared::TreeNode;

// Given a binary tree and a number ‘S’,
// find all paths from root-to-leaf such that the sum of all the node values of
// each path equals ‘S’.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

pub fn find_paths(root: &Option<Box<TreeNode>>, sum: i32) -> Vec<Vec<i32>> {
    let mut all_paths = Vec::new();
    let mut current_path = Vec::new();
    find_paths_recursive(root, sum, &mut current_path, &mut all_paths);
    all_paths
}

// find_paths_recursive to find paths recursively
fn find_paths_recursive(
    current_node: &Option<Box<TreeNode>>,
    sum: i32,
    current_path: &mut Vec<i32>,
    all_paths: &mut Vec<Vec<i32>>,
) {
    let Some(node) = current_node else {
        return;
    };

    // add the current node to the path
    current_path.push(node.val);

    if node.val == sum && node.left.is_none() && node.right.is_none() {
        // if the current node is a leaf and its value is equal to sum, save
        // the current path
        all_paths.push(current_path.clone());
    } else {
        // traverse the left sub-tree
        find_paths_recursive(
            &node.left,
            sum - node.val,
            current_path,
            all_paths,
        );
        // traverse the right sub-tree
        find_paths_recursive(
            &node.right,
            sum - node.val,
            current_path,
            all_paths,
        );
    }

    // remove the current node from the path to backtrack, we need to remove
    // the current node while we are going up the recursive call stack
    current_path.pop();
}
