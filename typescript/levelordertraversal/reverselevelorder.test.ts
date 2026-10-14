import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { traverse } from "./reverselevelorder.ts";

describe("traverse", () => {
  test.each([
    {
      name: "Example 1",
      root: [1, 2, 3, 4, 5, 6, 7],
      want: [[4, 5, 6, 7], [2, 3], [1]],
    },
    {
      name: "Example 2",
      root: [12, 7, 1, null, 9, 10, 5],
      want: [[9, 10, 5], [7, 1], [12]],
    },
    {
      name: "Example 3",
      root: [6, 5, 2, null, null, 1, 6, 3, 56, null, 3],
      want: [[3, 56, 3], [1, 6], [5, 2], [6]],
    },
    { name: "Empty tree", root: [], want: [] },
  ])("$name", ({ root, want }) => {
    expect(traverse(tree(root))).toEqual(want);
  });
});
