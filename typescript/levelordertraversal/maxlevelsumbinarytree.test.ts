import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { maxLevelSum } from "./maxlevelsumbinarytree.ts";

describe("maxLevelSum", () => {
  test.each([
    { name: "Example 1", root: [1, 20, 3, 4, 5, null, 8], want: 2 },
    {
      name: "Example 2",
      root: [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1],
      want: 3,
    },
    { name: "Example 3", root: [5, 6, 7, 8, null, null, 9, 10], want: 3 },
    { name: "Single node", root: [42], want: 1 },
    { name: "Negative values", root: [-1, -2, -3], want: 1 },
  ])("$name", ({ root, want }) => {
    expect(maxLevelSum(tree(root))).toBe(want);
  });
});
