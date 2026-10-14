import { describe, expect, test } from "vitest";

import { tree, type TreeNode } from "../common/tree.ts";
import { findUniqueTrees } from "./uniquebst.ts";

// shape writes a tree out in preorder, with '-' for a missing child, so that
// two trees with the same shape and values give the same text.
function shape(node: TreeNode | null): string {
  if (node === null) {
    return "-";
  }
  return `${String(node.value)}(${shape(node.left)} ${shape(node.right)})`;
}

describe("findUniqueTrees", () => {
  // each tree in level order
  test.each<{ name: string; n: number; want: (number | null)[][] }>([
    {
      name: "Example 1",
      n: 2,
      want: [
        [1, null, 2],
        [2, 1],
      ],
    },
    {
      name: "Example 2",
      n: 3,
      want: [
        [1, null, 2, null, 3],
        [1, null, 3, 2],
        [2, 1, 3],
        [3, 1, null, null, 2],
        [3, 2, null, 1],
      ],
    },
    { name: "Nothing to build", n: 0, want: [] },
  ])("$name", ({ n, want }) => {
    const got = findUniqueTrees(n).map(shape);
    expect(got).toEqual(want.map((root) => shape(tree(root))));
  });
});
