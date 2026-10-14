import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { findSumOfPathNumbers } from "./sumofpathnums.ts";

describe("findSumOfPathNumbers", () => {
  test.each([
    // Paths: 12, 13 => 12+13=25
    { name: "Example 1", root: [1, 2, 3], want: 25 },
    // Paths: 101, 106, 115 => 101+106+115=322
    //                       1
    //                     /   \
    //                    0     1
    //                   / \     \
    //                  1   6     5
    { name: "Example 2", root: [1, 0, 1, 1, 6, null, 5], want: 322 },
    { name: "Single node", root: [5], want: 5 },
    { name: "Empty tree", root: [], want: 0 },
  ])("$name", ({ root, want }) => {
    expect(findSumOfPathNumbers(tree(root))).toBe(want);
  });
});
