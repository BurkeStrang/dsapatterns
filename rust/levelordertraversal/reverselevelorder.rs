use std::collections::VecDeque;

use super::shared::TreeNode;

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

pub fn traverse(root: &Option<Box<TreeNode>>) -> Vec<Vec<i32>> {
    // a deque, so that a level can be put at the front cheaply
    let mut result = VecDeque::new();
    let Some(root) = root else {
        return Vec::new();
    };

    let mut queue = VecDeque::new();
    queue.push_back(root);
    while !queue.is_empty() {
        let level_size = queue.len();
        let mut current_level = Vec::with_capacity(level_size);
        for _ in 0..level_size {
            let current_node = queue.pop_front().unwrap();
            // add the node to the current level
            current_level.push(current_node.val);
            // insert the children of current node to the queue
            if let Some(left) = &current_node.left {
                queue.push_back(left);
            }
            if let Some(right) = &current_node.right {
                queue.push_back(right);
            }
        }
        // append the current level at the beginning
        result.push_front(current_level);
    }

    result.into()
}
