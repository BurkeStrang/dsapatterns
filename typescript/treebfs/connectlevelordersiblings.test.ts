import { describe, expect, test } from "vitest";

import { tree, type TreeNode } from "../common/tree.ts";
import { connect } from "./connectlevelordersiblings.ts";

// levelOrderNext walks the tree using next pointers and returns the values
// level by level.
function levelOrderNext(root: TreeNode | null): number[][] {
  const result: number[][] = [];
  let levelStart = root;
  while (levelStart !== null) {
    const level: number[] = [];
    let nextLevel: TreeNode | null = null;
    for (
      let node: TreeNode | null = levelStart;
      node !== null;
      node = node.next
    ) {
      level.push(node.value);
      nextLevel ??= node.left ?? node.right;
    }
    result.push(level);
    levelStart = nextLevel;
  }
  return result;
}

describe("connect", () => {
  test.each([
    {
      name: "Example 1",
      root: [1, 2, 3, 4, 5, 6, 7],
      want: [[1], [2, 3], [4, 5, 6, 7]],
    },
    {
      name: "Example 2",
      root: [12, 7, 1, 9, null, 10, 5],
      want: [[12], [7, 1], [9, 10, 5]],
    },
    { name: "Empty tree", root: [], want: [] },
  ])("$name", ({ root, want }) => {
    const node = tree(root);
    connect(node);
    expect(levelOrderNext(node)).toEqual(want);
  });
});
