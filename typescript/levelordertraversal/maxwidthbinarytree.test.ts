import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { widthOfBinaryTree } from "./maxwidthbinarytree.ts";

describe("widthOfBinaryTree", () => {
  test.each([
    { name: "Example 1", root: [1, 2, 3, 4, null, null, 5], want: 4 },
    { name: "Example 2", root: [1, 2, 3, 4, null, 5, 6, null, 7], want: 4 },
    { name: "Example 3", root: [1, 2, null, 3, 4, 5], want: 2 },
    { name: "Single node", root: [42], want: 1 },
    { name: "Empty tree", root: [], want: 0 },
  ])("$name", ({ root, want }) => {
    expect(widthOfBinaryTree(tree(root))).toBe(want);
  });
});
