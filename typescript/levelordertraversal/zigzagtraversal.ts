// Example 1:
// input: root = [3,9,20,null,null,15,7]
// output: [[3],[20,9],[15,7]]

import type { TreeNode } from "../common/tree.ts";

export function traverseZigZag(root: TreeNode | null): number[][] {
  const result: number[][] = [];
  if (root === null) {
    return result;
  }

  let level = [root];
  let leftToRight = true;
  while (level.length > 0) {
    const nextLevel: TreeNode[] = [];
    const currentLevel: number[] = [];
    for (const currentNode of level) {
      // add the node to the current level based on the traverse direction
      if (leftToRight) {
        currentLevel.push(currentNode.value);
      } else {
        currentLevel.unshift(currentNode.value);
      }

      // insert the children of current node for the next level
      if (currentNode.left !== null) {
        nextLevel.push(currentNode.left);
      }
      if (currentNode.right !== null) {
        nextLevel.push(currentNode.right);
      }
    }

    result.push(currentLevel);
    // reverse the traversal direction
    leftToRight = !leftToRight;
    level = nextLevel;
  }

  return result;
}
