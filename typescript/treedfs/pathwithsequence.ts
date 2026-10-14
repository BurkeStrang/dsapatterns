// Given a binary tree and a number sequence,
// find if the sequence is present as a root-to-leaf path in the given tree.

import type { TreeNode } from "../common/tree.ts";

export function findPathRecursive(
  currentNode: TreeNode | null,
  sequence: number[],
  sequenceIndex: number,
): boolean {
  if (currentNode === null) {
    return false;
  }

  const sequenceLength = sequence.length;
  if (
    sequenceIndex >= sequenceLength ||
    currentNode.value !== sequence[sequenceIndex]
  ) {
    return false;
  }

  // if the current node is a leaf, and it is the end of the sequence, we
  // have found a path!
  if (
    currentNode.left === null &&
    currentNode.right === null &&
    sequenceIndex === sequenceLength - 1
  ) {
    return true;
  }

  // recursively call to traverse the left and right sub-tree
  // return true if any of the two recursive call return true
  return (
    findPathRecursive(currentNode.left, sequence, sequenceIndex + 1) ||
    findPathRecursive(currentNode.right, sequence, sequenceIndex + 1)
  );
}

export function findPath(root: TreeNode | null, sequence: number[]): boolean {
  if (root === null) {
    return sequence.length === 0;
  }
  return findPathRecursive(root, sequence, 0);
}
