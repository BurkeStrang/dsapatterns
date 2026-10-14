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

import type { TreeNode } from "../common/tree.ts";

export function connect(root: TreeNode | null): void {
  if (root === null) {
    return;
  }

  let level = [root];
  while (level.length > 0) {
    const nextLevel: TreeNode[] = [];
    let previousNode: TreeNode | null = null;
    // connect all nodes of this level
    for (const currentNode of level) {
      if (previousNode !== null) {
        previousNode.next = currentNode;
      }
      previousNode = currentNode;

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
}
