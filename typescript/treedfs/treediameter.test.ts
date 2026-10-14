import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { findDiameter } from "./treediameter.ts";

describe("findDiameter", () => {
  test.each([
    { name: "Single node", root: [1], want: 0 },
    // Path: 4-2-1-3 or 5-2-1-3
    //            1
    //           / \
    //          2   3
    //         / \
    //        4   5
    { name: "Simple tree", root: [1, 2, 3, 4, 5], want: 4 },
    // Path: 4-1-2-3
    //       1
    //      / \
    //     4   2
    //          \
    //           3
    { name: "Lopsided tree", root: [1, 4, 2, null, null, null, 3], want: 4 },
  ])("$name", ({ root, want }) => {
    expect(findDiameter(tree(root))).toBe(want);
  });
});
