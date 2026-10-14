// Given a binary tree where each node can only have a digit (0-9) value,
// each root-to-leaf path will represent a number.
// Find the total sum of all the numbers represented by all paths.

import type { TreeNode } from "../common/tree.ts";

export function findPathSum(node: TreeNode | null, currentSum: number): number {
  if (node === null) {
    return 0;
  }

  // calculate the path number for the current node
  currentSum = currentSum * 10 + node.value;

  // if it's a leaf node, return the current path sum
  if (node.left === null && node.right === null) {
    return currentSum;
  }

  // traverse left and right subtrees
  return (
    findPathSum(node.left, currentSum) + findPathSum(node.right, currentSum)
  );
}

export function findSumOfPathNumbers(root: TreeNode | null): number {
  return findPathSum(root, 0);
}
