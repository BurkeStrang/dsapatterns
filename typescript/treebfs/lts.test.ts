import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { traverseBasic } from "./lts.ts";

describe("traverseBasic", () => {
  test.each([
    {
      name: "Example 1",
      root: [1, 2, 3, 4, 5, null, 6],
      want: [[1], [2, 3], [4, 5, 6]],
    },
    { name: "Single node", root: [42], want: [[42]] },
    { name: "Empty tree", root: [], want: [] },
  ])("$name", ({ root, want }) => {
    expect(traverseBasic(tree(root))).toEqual(want);
  });
});
