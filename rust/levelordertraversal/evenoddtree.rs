use std::collections::VecDeque;

use super::shared::TreeNode;

// Given a binary tree, return true if it is an Even-Odd tree. Otherwise, return
// false.
// The Even-odd tree must follow below two rules:
//
// At every even-indexed level (starting from 0),
// all node values must be odd and arranged in strictly increasing order from
// left to right.
// At every odd-indexed level,
// all node values must be even and arranged in strictly decreasing order from
// left to right.
//
// Example 1
// Input:
//     1
//    / \
//   10  4
//  / \
// 3   7
// Expected Output: true
// Justification: The tree follows both conditions for each odd and even level.
// So, it is an odd-even tree.
//
// Example 2
// Input:
//
//     5
//    / \
//   9   3
//  /     \
// 12      8
// Expected Output: false
// Justification: Level 1 has Odd values 9 and 3 in decreasing order, but it
// should have even values. So, the tree is not an odd-even tree.
//
// Example 3
// Input:
//     7
//    / \
//   10  2
//  / \
// 12  8
// Expected Output: false
// Justification: At level 2 (even-indexed), the values are 12 and 8, which are
// even, but they should have odd values. So, the tree is not an odd-even tree.
//
// Constraints:
// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 10^6

pub fn is_even_odd_tree(root: &Option<Box<TreeNode>>) -> bool {
    let Some(root) = root else {
        return true; // Check if the tree is empty
    };

    let mut queue = VecDeque::new();
    queue.push_back(root);
    let mut level = 0; // Start with level 0

    while !queue.is_empty() {
        let size = queue.len();
        let mut values = Vec::new(); // Node values at the current level

        for _ in 0..size {
            let node = queue.pop_front().unwrap(); // Take the next node
            values.push(node.val);

            // Add the children to the queue if they exist
            if let Some(left) = &node.left {
                queue.push_back(left);
            }
            if let Some(right) = &node.right {
                queue.push_back(right);
            }
        }

        // Check values for the current level
        if level % 2 == 0 {
            // Even level: values must be odd and strictly increasing
            for i in 0..values.len() {
                if values[i] % 2 == 0 || (i > 0 && values[i] <= values[i - 1]) {
                    return false;
                }
            }
        } else {
            // Odd level: values must be even and strictly decreasing
            for i in 0..values.len() {
                if values[i] % 2 != 0 || (i > 0 && values[i] >= values[i - 1]) {
                    return false;
                }
            }
        }

        level += 1; // Move to the next level
    }

    true // If all levels satisfy the conditions, return true
}
