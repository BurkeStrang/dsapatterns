// Given the root of a binary tree, return an array containing the largest value
// in each row of the tree (0-indexed).
//
// Examples
// Example 1
// Input: root = [1, 2, 3, 4, 5, null, 6]
// Expected Output: [1, 3, 6]
// Image
// Justification:
// The first row contains 1. The largest value is 1.
// The second row has 2 and 3, and the largest is 3.
// The third row has 4, 5, and 6, and the largest is 6.
// Example 2
// Input: root = [7, 4, 8, 2, 5, null, 9, null, 3]
// Expected Output: [7, 8, 9, 3]
// Image
// Justification:
// The first row contains 7, and the largest value is 7.
// The second row has 4 and 8, and the largest is 8.
// The third row has 2, 5, and 9, and the largest is 9.
// The fourth row has 3, and the largest is 3.
// Example 3
// Input: root = [10, 5]
// Expected Output: [10, 5]
// Justification:
// The first row has 10, and the largest value is 10.
// The second row contains 5, and the largest is 5.
// Constraints:
//
// The number of nodes in the tree will be in the range [0, 104].
// -231 <= Node.val <= 231 - 1

import type { TreeNode } from "../common/tree.ts";

export function largestValues(root: TreeNode | null): number[] {
  const result: number[] = [];
  // Return an empty list if the root is null
  if (root === null) {
    return result;
  }

  // Level order traversal, one level at a time
  let level = [root];
  while (level.length > 0) {
    const nextLevel: TreeNode[] = [];
    let maxVal = -Infinity;

    // Traverse all nodes at the current level
    for (const node of level) {
      // Find the maximum value at the current level
      maxVal = Math.max(maxVal, node.value);

      // Add left and right children for the next level
      if (node.left !== null) {
        nextLevel.push(node.left);
      }
      if (node.right !== null) {
        nextLevel.push(node.right);
      }
    }

    // Store the largest value of the current level
    result.push(maxVal);
    level = nextLevel;
  }

  return result;
}
