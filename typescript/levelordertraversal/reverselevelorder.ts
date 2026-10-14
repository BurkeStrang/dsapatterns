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

import type { TreeNode } from "../common/tree.ts";

export function traverse(root: TreeNode | null): number[][] {
  const result: number[][] = [];
  if (root === null) {
    return result;
  }

  let level = [root];
  while (level.length > 0) {
    const nextLevel: TreeNode[] = [];
    const currentLevel: number[] = [];
    for (const currentNode of level) {
      // add the node to the current level
      currentLevel.push(currentNode.value);
      // insert the children of current node for the next level
      if (currentNode.left !== null) {
        nextLevel.push(currentNode.left);
      }
      if (currentNode.right !== null) {
        nextLevel.push(currentNode.right);
      }
    }

    // append the current level at the beginning
    result.unshift(currentLevel);
    level = nextLevel;
  }

  return result;
}
