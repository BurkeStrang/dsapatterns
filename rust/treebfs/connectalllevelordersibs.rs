use std::collections::VecDeque;
use std::rc::Rc;

use super::shared::Tree;

// Given a root of the binary tree, connect each node with its level order
// successor.
// The last node of each level should point to the first node of the next level.
//
// Example 1
// Input: root = [1, 2, 3, 4, 5, 6, 7]
// Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null
// Explanation: The tree is traversed level by level using BFS.
// Each node is connected to its next node in level order traversal,
// including connections between levels. The last node (7) points to null.
//
// Example 2
// Input: root = [12, 7, 1, 9, null, 10, 5]
// Image
// Output: 12 -> 7 -> 1 -> 9 -> 10 -> 5 -> null
// Explanation: Each node is connected to its next node in level order
// traversal.
// The last node (5) points to null, completing the connection of all level
// order siblings.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 212 - 1].
// -1000 <= Node.val <= 1000

// connect method to link tree nodes

pub fn connect_all(root: &Tree) {
    let Some(root) = root else {
        return;
    };

    let mut queue = VecDeque::new();
    queue.push_back(Rc::clone(root));
    let mut previous_node: Tree = None;
    while let Some(current_node) = queue.pop_front() {
        if let Some(previous_node) = previous_node {
            previous_node.borrow_mut().next = Some(Rc::clone(&current_node));
        }

        // insert the children of current node in the queue
        queue.extend(current_node.borrow().left.clone());
        queue.extend(current_node.borrow().right.clone());

        previous_node = Some(current_node);
    }
}
