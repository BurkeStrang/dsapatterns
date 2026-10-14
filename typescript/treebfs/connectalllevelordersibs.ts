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

import type { TreeNode } from "../common/tree.ts";

// connectAll links every node to the next one in level order
export function connectAll(root: TreeNode | null): void {
  if (root === null) {
    return;
  }

  // a for-of loop over an array also visits the items pushed onto it while
  // the loop runs, so the array works as the queue
  const queue = [root];
  let previousNode: TreeNode | null = null;
  for (const currentNode of queue) {
    if (previousNode !== null) {
      previousNode.next = currentNode;
    }
    previousNode = currentNode;

    // insert the children of current node in the queue
    if (currentNode.left !== null) {
      queue.push(currentNode.left);
    }
    if (currentNode.right !== null) {
      queue.push(currentNode.right);
    }
  }
}
