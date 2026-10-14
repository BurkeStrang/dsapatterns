import { describe, expect, test } from "vitest";

import { tree, type TreeNode } from "../common/tree.ts";
import { connectAll } from "./connectalllevelordersibs.ts";

// flattenNext walks the tree using next pointers and returns the values in
// order.
function flattenNext(root: TreeNode | null): number[] {
  const result: number[] = [];
  for (let node = root; node !== null; node = node.next) {
    result.push(node.value);
  }
  return result;
}

describe("connectAll", () => {
  test.each([
    {
      name: "Example 1",
      root: [1, 2, 3, 4, 5, 6, 7],
      want: [1, 2, 3, 4, 5, 6, 7],
    },
    {
      name: "Example 2",
      root: [12, 7, 1, 9, null, 10, 5],
      want: [12, 7, 1, 9, 10, 5],
    },
    { name: "Empty tree", root: [], want: [] },
  ])("$name", ({ root, want }) => {
    const node = tree(root);
    connectAll(node);
    expect(flattenNext(node)).toEqual(want);
  });
});
