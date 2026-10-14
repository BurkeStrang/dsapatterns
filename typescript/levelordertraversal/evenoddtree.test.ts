import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { isEvenOddTree } from "./evenoddtree.ts";

describe("isEvenOddTree", () => {
  test.each([
    {
      name: "Example 1: Valid Even-Odd Tree",
      root: [1, 10, 4, 3, 7],
      want: true,
    },
    {
      name: "Example 2: Invalid Even-Odd Tree (odd values at level 1)",
      root: [5, 9, 3, 12, null, null, 8],
      want: false,
    },
    {
      name: "Example 3: Invalid Even-Odd Tree (even values at even level)",
      root: [7, 10, 2, 12, 8],
      want: false,
    },
    { name: "Single node (odd value at level 0)", root: [1], want: true },
    { name: "Single node (even value at level 0)", root: [2], want: false },
    { name: "Empty tree", root: [], want: true },
  ])("$name", ({ root, want }) => {
    expect(isEvenOddTree(tree(root))).toBe(want);
  });
});
