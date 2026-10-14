use std::collections::VecDeque;

use super::shared::TreeNode;

// Given the root of a binary tree, find the maximum width of the tree.
// The maximum width is the widest level in the tree.
// The width of a level is the number of nodes between the leftmost and
// rightmost non-null nodes, where the null nodes between the end-nodes that
// would be present in a complete binary tree extending down to that level are
// also counted into the length calculation.
// You can assume that the result will fit within a 32-bit signed integer.
//
// Example 1
// Input: root = [1, 2, 3, 4, null, null, 5]
// Image
// Output: 4
// Justification: The maximum width is at the last level between nodes 4 and 5.
// It counts four positions: [4, null, null, 5].
//
// Example 2
// Input: root = [1, 2, 3, 4, null, 5, 6, null, 7]
// Image
// Output: 4
// Justification: The maximum width is between nodes 4 and 6 at level 3,
// counting four positions: [4, null, 5, 6].
//
// Example 3
// Input: root = [1, 2, null, 3, 4, null, null, 5]
// Image
// Output: 2
// Justification: The maximum width is at the third level, between nodes 3 and
// 4. It counts two positions: [3, 4].
//
// Constraints:
// The number of nodes in the tree is in the range [1, 3000].
// -100 <= Node.val <= 100

// Method to find the maximum width of the binary tree

pub fn width_of_binary_tree(root: &Option<Box<TreeNode>>) -> usize {
    let Some(root) = root else {
        return 0;
    };

    // each entry is a node and its position within its level
    let mut queue = VecDeque::new();
    queue.push_back((root, 0)); // Add the root node with position 0
    let mut max_width = 0; // Initialize maximum width

    // Level order traversal using queue
    while !queue.is_empty() {
        let size = queue.len();
        // Get the minimum index at this level to normalize positions
        let min_index = queue[0].1;
        let mut first = 0;
        let mut last = 0;

        for i in 0..size {
            let (node, index) = queue.pop_front().unwrap();
            // Normalize the index to prevent overflow
            let index = index - min_index;

            // Record the first and last positions at the current level
            if i == 0 {
                first = index;
            }
            if i == size - 1 {
                last = index;
            }

            // Enqueue left child with the correct position if it exists
            if let Some(left) = &node.left {
                queue.push_back((left, 2 * index));
            }
            // Enqueue right child with the correct position if it exists
            if let Some(right) = &node.right {
                queue.push_back((right, 2 * index + 1));
            }
        }

        // Calculate the width of the current level and update max_width
        max_width = max_width.max(last - first + 1);
    }

    max_width
}
