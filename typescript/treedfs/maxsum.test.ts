import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { findMaximumPathSum } from "./maxsum.ts";

describe("findMaximumPathSum", () => {
  test.each([
    // 2 + 1 + 3
    { name: "simple tree", root: [1, 2, 3], want: 6 },
    // 15 + 20 + 7
    {
      name: "tree with negative values",
      root: [-10, 9, 20, null, null, 15, 7],
      want: 42,
    },
  ])("$name", ({ root, want }) => {
    expect(findMaximumPathSum(tree(root))).toBe(want);
  });
});
