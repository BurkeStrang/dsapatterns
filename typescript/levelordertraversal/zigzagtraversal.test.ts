import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { traverseZigZag } from "./zigzagtraversal.ts";

describe("traverseZigZag", () => {
  test.each([
    {
      name: "Example 1",
      root: [1, 2, 3, 4, 5, null, 6],
      want: [[1], [3, 2], [4, 5, 6]],
    },
    {
      name: "Example 2",
      root: [7, 4, 8, 2, 5, null, 9, null, 3],
      want: [[7], [8, 4], [2, 5, 9], [3]],
    },
    { name: "Single node", root: [42], want: [[42]] },
    { name: "Empty tree", root: [], want: [] },
  ])("$name", ({ root, want }) => {
    expect(traverseZigZag(tree(root))).toEqual(want);
  });
});
