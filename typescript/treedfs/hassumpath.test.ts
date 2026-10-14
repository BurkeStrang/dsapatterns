import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { hasPath } from "./hassumpath.ts";

describe("hasPath", () => {
  test.each([
    { name: "Example 1", root: [1, 2, 3, 4, 5, 6, 7], sum: 10, want: true },
    {
      name: "Example 2",
      root: [12, 7, 1, 9, null, 10, 5],
      sum: 23,
      want: true,
    },
    {
      name: "Example 3",
      root: [12, 7, 1, 9, null, 10, 5],
      sum: 16,
      want: false,
    },
    { name: "Empty tree", root: [], sum: 0, want: false },
  ])("$name", ({ root, sum, want }) => {
    expect(hasPath(tree(root), sum)).toBe(want);
  });
});
