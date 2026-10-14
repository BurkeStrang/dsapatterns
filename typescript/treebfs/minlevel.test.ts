import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { findDepth } from "./minlevel.ts";

describe("findDepth", () => {
  test.each([
    { name: "Example 1", root: [1, 2, 3, 4, 5], want: 2 },
    { name: "Example 2", root: [1, 2], want: 2 },
    { name: "Example 3", root: [1, 2, 3, 4, 5, 6], want: 3 },
    { name: "Example 4", root: [1], want: 1 },
    { name: "Empty tree", root: [], want: 0 },
  ])("$name", ({ root, want }) => {
    expect(findDepth(tree(root))).toBe(want);
  });
});
