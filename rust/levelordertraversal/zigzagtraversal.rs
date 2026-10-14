use std::collections::VecDeque;

use super::shared::TreeNode;

// Example 1:
// input: root = [3,9,20,null,null,15,7]
// output: [[3],[20,9],[15,7]]

pub fn traverse_zig_zag(root: &Option<Box<TreeNode>>) -> Vec<Vec<i32>> {
    let mut result = Vec::new();
    let Some(root) = root else {
        return result;
    };

    let mut queue = VecDeque::new();
    queue.push_back(root);
    let mut left_to_right = true;
    while !queue.is_empty() {
        let level_size = queue.len();
        let mut current_level = VecDeque::new();
        for _ in 0..level_size {
            let current_node = queue.pop_front().unwrap();

            // add the node to the current level based on the traverse
            // direction
            if left_to_right {
                current_level.push_back(current_node.val);
            } else {
                current_level.push_front(current_node.val);
            }

            // insert the children of current node in the queue
            if let Some(left) = &current_node.left {
                queue.push_back(left);
            }
            if let Some(right) = &current_node.right {
                queue.push_back(right);
            }
        }
        result.push(current_level.into());
        // reverse the traversal direction
        left_to_right = !left_to_right;
    }

    result
}
