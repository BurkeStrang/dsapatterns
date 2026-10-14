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

import type { TreeNode } from "../common/tree.ts";

export function findDepth(root: TreeNode | null): number {
  if (root === null) {
    return 0;
  }

  let level = [root];
  let minimumTreeDepth = 0;
  while (level.length > 0) {
    minimumTreeDepth++;
    const nextLevel: TreeNode[] = [];
    for (const currentNode of level) {
      // check if this is a leaf node
      if (currentNode.left === null && currentNode.right === null) {
        return minimumTreeDepth;
      }

      // insert the children of current node for the next level
      if (currentNode.left !== null) {
        nextLevel.push(currentNode.left);
      }
      if (currentNode.right !== null) {
        nextLevel.push(currentNode.right);
      }
    }
    level = nextLevel;
  }

  return minimumTreeDepth;
}
