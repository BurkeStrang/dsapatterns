import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { countPaths } from "./countpathssum.ts";

describe("countPaths", () => {
  test.each([
    // Paths: [1,2], [3]
    { name: "Example 1: Two paths", root: [1, 2, 3], targetSum: 3, want: 2 },
    // Paths: [5,3], [5,2,1], [-3,11]
    {
      name: "Example 2: Multiple paths",
      root: [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1],
      targetSum: 8,
      want: 3,
    },
    { name: "Example 3: No path", root: [1, 2], targetSum: 100, want: 0 },
    { name: "Example 4: Empty tree", root: [], targetSum: 0, want: 0 },
  ])("$name", ({ root, targetSum, want }) => {
    expect(countPaths(tree(root), targetSum)).toBe(want);
  });
});
