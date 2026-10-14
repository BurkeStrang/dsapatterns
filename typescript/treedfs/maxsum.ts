// Find the path with the maximum sum in a given binary tree.
// Write a function that returns the maximum sum.
// A path can be defined as a sequence of nodes between any two nodes and
// doesn’t necessarily pass through the root.
// The path must contain at least one node.

import type { TreeNode } from "../common/tree.ts";

// Constraints:
// The number of nodes in the tree is in the range [1, 3 * 10^4].
// -1000 <= Node.val <= 1000

// findMaximumPathSum starts the recursive process and returns the result
export function findMaximumPathSum(root: TreeNode | null): number {
  let globalMaximumSum = -Infinity;

  // findMaximumPathSumRecursive returns the maximum sum of any path going
  // down from currentNode, and updates globalMaximumSum with the best path
  // through it
  const findMaximumPathSumRecursive = (
    currentNode: TreeNode | null,
  ): number => {
    if (currentNode === null) {
      return 0;
    }

    let maxPathSumFromLeft = findMaximumPathSumRecursive(currentNode.left);
    let maxPathSumFromRight = findMaximumPathSumRecursive(currentNode.right);

    // ignore paths with negative sums
    maxPathSumFromLeft = Math.max(maxPathSumFromLeft, 0);
    maxPathSumFromRight = Math.max(maxPathSumFromRight, 0);

    // local maximum sum
    const localMaximumSum =
      maxPathSumFromLeft + maxPathSumFromRight + currentNode.value;

    // update the global maximum sum
    globalMaximumSum = Math.max(globalMaximumSum, localMaximumSum);

    // return the maximum sum of any path from the current node
    return (
      Math.max(maxPathSumFromLeft, maxPathSumFromRight) + currentNode.value
    );
  };

  findMaximumPathSumRecursive(root);
  return globalMaximumSum;
}
