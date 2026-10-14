use std::collections::VecDeque;

use super::shared::NAryNode;

// Given an n-ary tree, return a list representing the level order traversal of
// the nodes' values in this tree.
// The input tree is serialized in an array format using level order traversal,
// where the children of each node are grouped together and separated by a null
// value.
//
// Example 1
// Input: root = [1, null, 2, 3, 4, null, 5, 6]
// Image
// Expected Output: [[1], [2, 3, 4], [5, 6]]
// Justification: The root node 1 is at level 0. Nodes 2, 3, and 4 are the
// children of 1 and are at level 1. Nodes 5 and 6 are the children of 2, and at
// level 3.
//
// Example 2
// Input: root = [7, null, 3, 8, 5, null, 2, 9, null, 6, null, 1, 4, 10]
// Image
// Expected Output: [[7], [3, 8, 5], [2, 9, 6, 1, 4, 10]]
// Justification: The root node 7 is at level 0. Nodes 3, 8, and 5 are its
// children at level 1. Nodes 2, 9, 6, 1, 4, and 10 are at level 2.
//
// Example 3
// Input: root = [10, null, 15, 12, null, 20, null, 25, null, 30, 40]
// Image
// Expected Output: [[10], [15, 12], [20, 25], [30, 40]]
// Justification: The root node 10 is at level 0. Nodes 15 and 12 are its
// children at level 1. Node 20 and 25 are at level 2. Nodes 30, and 40 are at
// level 3.
//
// Constraints:
// The height of the n-ary tree is less than or equal to 1000
// The total number of nodes is between [0, 104]

pub fn level_order(root: Option<&NAryNode>) -> Vec<Vec<i32>> {
    let mut result = Vec::new(); // Result list to store levels
    let Some(root) = root else {
        return result;
    };

    let mut queue = VecDeque::new();
    queue.push_back(root);

    while !queue.is_empty() {
        let size = queue.len();
        let mut level = Vec::new(); // List to store current level nodes

        for _ in 0..size {
            let node = queue.pop_front().unwrap(); // Dequeue the front node
            level.push(node.val); // Add node value to the current level
            queue.extend(&node.children); // Enqueue all of its children
        }

        result.push(level); // Add the current level to the result
    }

    result // Return the level order traversal
}
