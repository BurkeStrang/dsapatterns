import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { rightView } from "./rightviewbinarytree.ts";

describe("rightView", () => {
  test.each([
    { name: "Example 1", root: [1, 2, 3, 4, 5, 6, 7], want: [1, 3, 7] },
    {
      name: "Example 2",
      root: [12, 7, 1, null, 9, 10, 5, null, 3],
      want: [12, 1, 5, 3],
    },
    {
      name: "Example 3",
      root: [8, 4, 9, 3, null, null, 10, 2],
      want: [8, 9, 10, 2],
    },
    { name: "Empty tree", root: [], want: [] },
  ])("$name", ({ root, want }) => {
    expect(rightView(tree(root))).toEqual(want);
  });
});
