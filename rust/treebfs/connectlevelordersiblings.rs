use std::collections::VecDeque;
use std::rc::Rc;

use super::shared::Tree;

// Given a root of the binary tree, connect each node with its level order
// successor.
// The last node of each level should point to a null node.
//
// Example 1:
// Input: root = [1, 2, 3, 4, 5, 6, 7]
// Output:
// [1 -> null]
// [2 -> 3 -> null]
// [4 -> 5 -> 6 -> 7 -> null]
// Explanation:
// The tree is traversed level by level using BFS. Each node is connected to its
// next right node at the same level. The last node of each level points to
// null.
//
// Example 2:
// Input: root = [12, 7, 1, 9, null, 10, 5]
// Output:
// [12 -> null]
// [7 -> 1 -> null]
// [9 -> 10 -> 5 -> null]
// Explanation:
// The nodes are connected to their next right sibling at the same level. The
// last node of each level points to null.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 2^12 - 1].
// -1000 <= Node.val <= 1000

pub fn connect(root: &Tree) {
    let Some(root) = root else {
        return;
    };

    let mut queue = VecDeque::new();
    queue.push_back(Rc::clone(root));
    while !queue.is_empty() {
        let mut previous_node: Tree = None;
        let level_size = queue.len();
        // connect all nodes of this level
        for _ in 0..level_size {
            let current_node = queue.pop_front().unwrap();
            if let Some(previous_node) = previous_node {
                previous_node.borrow_mut().next =
                    Some(Rc::clone(&current_node));
            }

            // insert the children of current node in the queue
            queue.extend(current_node.borrow().left.clone());
            queue.extend(current_node.borrow().right.clone());

            previous_node = Some(current_node);
        }
    }
}
