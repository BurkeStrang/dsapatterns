use super::shared::TreeNode;

// Given a binary tree and a number sequence,
// find if the sequence is present as a root-to-leaf path in the given tree.

pub fn find_path(root: &Option<Box<TreeNode>>, sequence: &[i32]) -> bool {
    if root.is_none() {
        return sequence.is_empty();
    }

    find_path_recursive(root, sequence, 0)
}

fn find_path_recursive(
    current_node: &Option<Box<TreeNode>>,
    sequence: &[i32],
    sequence_index: usize,
) -> bool {
    let Some(node) = current_node else {
        return false;
    };

    if sequence_index >= sequence.len() || node.val != sequence[sequence_index]
    {
        return false;
    }

    // if the current node is a leaf, and it is the end of the sequence, we
    // have found a path!
    if node.left.is_none()
        && node.right.is_none()
        && sequence_index == sequence.len() - 1
    {
        return true;
    }

    // recursively call to traverse the left and right sub-tree
    // return true if any of the two recursive call return true
    find_path_recursive(&node.left, sequence, sequence_index + 1)
        || find_path_recursive(&node.right, sequence, sequence_index + 1)
}
