// Given a binary tree, find the length of its diameter.
// The diameter of a tree is the number of nodes on the longest path between any
// two leaf nodes.
// The diameter of a tree may or may not pass through the root.
// Note: You can always assume that there are at least two leaf nodes in the
// given tree.
//
// Constraints:
// n == edges.length + 1
// 1 <= n <= 104
// 0 <= ai, bi < n
// ai != bi

import type { TreeNode } from "../common/tree.ts";

export function findDiameter(root: TreeNode | null): number {
  let treeDiameter = 0;

  // calculateHeight returns the height of currentNode, and updates
  // treeDiameter with the longest path through it
  const calculateHeight = (currentNode: TreeNode | null): number => {
    if (currentNode === null) {
      return 0;
    }

    const leftTreeHeight = calculateHeight(currentNode.left);
    const rightTreeHeight = calculateHeight(currentNode.right);

    // if the current node doesn't have a left or right subtree, we can't
    // have a path passing through it, since we need a leaf node on each side
    if (leftTreeHeight !== 0 && rightTreeHeight !== 0) {
      // diameter at the current node will be equal to the height of left
      // subtree + the height of right sub-trees + '1' for the current node
      const diameter = leftTreeHeight + rightTreeHeight + 1;

      // update the global tree diameter
      treeDiameter = Math.max(treeDiameter, diameter);
    }

    // height of the current node will be equal to the maximum of the heights
    // of left or right subtrees plus '1' for the current node
    return Math.max(leftTreeHeight, rightTreeHeight) + 1;
  };

  calculateHeight(root);
  return treeDiameter;
}
