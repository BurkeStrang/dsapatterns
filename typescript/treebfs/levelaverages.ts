// Given a binary tree,Given a binary tree, populate an array to represent its
// level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.
// populate an array to represent its level-by-level traversal.
// You should populate the values of all nodes of each level from left to right
// in separate sub-arrays.

import type { TreeNode } from "../common/tree.ts";

export function levelAverage(root: TreeNode | null): number[] {
  const result: number[] = [];
  if (root === null) {
    return result;
  }

  let level = [root];
  while (level.length > 0) {
    const nextLevel: TreeNode[] = [];
    let levelSum = 0;
    for (const currentNode of level) {
      // add the node's value to the running sum
      levelSum += currentNode.value;
      // insert the children of current node for the next level
      if (currentNode.left !== null) {
        nextLevel.push(currentNode.left);
      }
      if (currentNode.right !== null) {
        nextLevel.push(currentNode.right);
      }
    }

    // append the current level's average to the result array
    result.push(levelSum / level.length);
    level = nextLevel;
  }

  return result;
}
