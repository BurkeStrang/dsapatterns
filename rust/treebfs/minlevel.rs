use std::collections::VecDeque;
use std::rc::Rc;

use super::shared::Tree;

// Given a root of the binary tree, find the minimum depth of a binary tree.
// The minimum depth is the number of nodes along the shortest path from the
// root node to the nearest leaf node.
//
// Example 1
// Input: [1,2,3,4,5]
// Output: 2
//
// Example 2
// Input: [1,2]
// Output: 2
//
// Example 3
// Input: [1,2,3,4,5,6]
// Output: 3
//
// Example 4
// Input: [1]
// Output: 1
//
// Constraints:
// The number of nodes in the tree is in the range [0, 10^5].
// -1000 <= Node.val <= 1000

pub fn find_depth(root: &Tree) -> usize {
    let Some(root) = root else {
        return 0;
    };

    let mut queue = VecDeque::new();
    queue.push_back(Rc::clone(root));
    let mut minimum_tree_depth = 0;
    while !queue.is_empty() {
        minimum_tree_depth += 1;
        let level_size = queue.len();
        for _ in 0..level_size {
            let current_node = queue.pop_front().unwrap();
            let current_node = current_node.borrow();

            // check if this is a leaf node
            if current_node.left.is_none() && current_node.right.is_none() {
                return minimum_tree_depth;
            }

            // insert the children of current node in the queue
            queue.extend(current_node.left.clone());
            queue.extend(current_node.right.clone());
        }
    }
    minimum_tree_depth
}
