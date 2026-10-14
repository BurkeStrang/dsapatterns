use std::collections::VecDeque;
use std::rc::Rc;

use super::shared::Tree;

// Given a binary tree,Given a binary tree, populate an array to represent its
// level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.
// populate an array to represent its level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.

pub fn traverse_basic(root: &Tree) -> Vec<Vec<i32>> {
    let mut result = Vec::new();
    let Some(root) = root else {
        return result;
    };

    let mut queue = VecDeque::new();
    queue.push_back(Rc::clone(root));
    while !queue.is_empty() {
        let level_size = queue.len();
        let mut current_level = Vec::with_capacity(level_size);
        for _ in 0..level_size {
            let current_node = queue.pop_front().unwrap();
            let current_node = current_node.borrow();
            // add the node to the current level
            current_level.push(current_node.val);
            // insert the children of current node in the queue
            queue.extend(current_node.left.clone());
            queue.extend(current_node.right.clone());
        }
        result.push(current_level);
    }
    result
}
