// Given a binary tree and a number ‘S’,
// find all paths from root-to-leaf such that the sum of all the node values of
// each path equals ‘S’.
//
// Constraints:
// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

import type { TreeNode } from "../common/tree.ts";

// findPathsRecursive finds the paths recursively
export function findPathsRecursive(
  currentNode: TreeNode | null,
  sum: number,
  currentPath: number[],
  allPaths: number[][],
): void {
  if (currentNode === null) {
    return;
  }

  // add the current node to the path
  currentPath.push(currentNode.value);

  if (
    currentNode.value === sum &&
    currentNode.left === null &&
    currentNode.right === null
  ) {
    // if the current node is a leaf and its value is equal to sum, save a
    // copy of the current path
    allPaths.push([...currentPath]);
  } else {
    // traverse the left sub-tree
    findPathsRecursive(
      currentNode.left,
      sum - currentNode.value,
      currentPath,
      allPaths,
    );
    // traverse the right sub-tree
    findPathsRecursive(
      currentNode.right,
      sum - currentNode.value,
      currentPath,
      allPaths,
    );
  }

  // remove the current node from the path to backtrack, we need to remove
  // the current node while we are going up the recursive call stack
  currentPath.pop();
}

export function findPaths(root: TreeNode | null, sum: number): number[][] {
  const allPaths: number[][] = [];
  findPathsRecursive(root, sum, [], allPaths);
  return allPaths;
}
