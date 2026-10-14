// Given a binary tree and a number ‘S’,
// find all paths in the tree such that the sum of all the node values of each
// path equals ‘S’.
// Please note that the paths can start or end at
// any node but all paths must follow direction from parent to child (top to
// bottom).

import type { TreeNode } from "../common/tree.ts";

export function countPathsPrefixSum(
  node: TreeNode | null,
  targetSum: number,
  m: Map<number, number>,
  currentPathSum: number,
): number {
  if (node === null) {
    return 0;
  }

  // The number of paths that have the required sum.
  let pathCount = 0;

  // 'currentPathSum' is the prefix sum, i.e., sum of all node values from
  // the root to the current node.
  currentPathSum += node.value;

  // This is the base case. If the current sum is equal to the target sum,
  // we have found a path from root to the current node having the required
  // sum. Hence, we increment the path count by 1.
  if (targetSum === currentPathSum) {
    pathCount++;
  }

  // 'currentPathSum' is the path sum from root to the current node. If
  // within this path, there is a valid solution, then there must be an
  // 'oldPathSum' such that:
  // => currentPathSum - oldPathSum = targetSum
  // => currentPathSum - targetSum = oldPathSum
  // Hence, we can search such an 'oldPathSum' in the map from the key
  // 'currentPathSum - targetSum'.
  pathCount += m.get(currentPathSum - targetSum) ?? 0;

  // This is the key step in the algorithm. We are storing the number of
  // times the prefix sum `currentPathSum` has occurred so far.
  m.set(currentPathSum, (m.get(currentPathSum) ?? 0) + 1);

  // Counting the number of paths from the left and right subtrees.
  pathCount += countPathsPrefixSum(node.left, targetSum, m, currentPathSum);
  pathCount += countPathsPrefixSum(node.right, targetSum, m, currentPathSum);

  // Removing the current path sum from the map for backtracking.
  // 'currentPathSum' is the prefix sum up to the current node. When we go
  // back (i.e., backtrack), then the current node is no more a part of the
  // path, hence, we should remove its prefix sum from the map.
  m.set(currentPathSum, (m.get(currentPathSum) ?? 0) - 1);

  return pathCount;
}

export function countPaths(root: TreeNode | null, targetSum: number): number {
  // A map that stores the number of times a prefix sum has occurred so far.
  const m = new Map<number, number>();
  return countPathsPrefixSum(root, targetSum, m, 0);
}
