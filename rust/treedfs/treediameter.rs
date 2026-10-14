use super::shared::TreeNode;

// Given a binary tree, find the length of its diameter.
// The diameter of a tree is the number of nodes on the longest path between any
// two leaf nodes.
// The diameter of a tree may or may not pass through the root.
// Note: You can always assume that there are at least two leaf nodes in the
// given tree.
//
// Constraints:
// n == edges.length + 1
// 1 <= n <= 104
// 0 <= ai, bi < n
// ai != bi

pub fn find_diameter(root: &Option<Box<TreeNode>>) -> usize {
    let mut tree_diameter = 0;
    calculate_height(root, &mut tree_diameter);
    tree_diameter
}

fn calculate_height(
    current_node: &Option<Box<TreeNode>>,
    tree_diameter: &mut usize,
) -> usize {
    let Some(node) = current_node else {
        return 0;
    };

    let left_tree_height = calculate_height(&node.left, tree_diameter);
    let right_tree_height = calculate_height(&node.right, tree_diameter);

    // if the current node doesn't have a left or right subtree, we can't have
    // a path passing through it, since we need a leaf node on each side
    if left_tree_height != 0 && right_tree_height != 0 {
        // diameter at the current node will be equal to the height of left
        // subtree + the height of right sub-trees + '1' for the current node
        let diameter = left_tree_height + right_tree_height + 1;

        // update the global tree diameter
        *tree_diameter = (*tree_diameter).max(diameter);
    }

    // height of the current node will be equal to the maximum of the heights
    // of left or right subtrees plus '1' for the current node
    left_tree_height.max(right_tree_height) + 1
}
