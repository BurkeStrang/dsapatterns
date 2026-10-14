import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { findPaths } from "./allpathsforsum.ts";

const TWO_PATHS = [5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1];

describe("findPaths", () => {
  test.each([
    {
      name: "Example 1",
      root: [1, 2, 3, 4, 5, 6, 7],
      sum: 10,
      want: [[1, 3, 6]],
    },
    {
      name: "Example 2",
      root: [12, 7, 1, 9, null, 10, 5],
      sum: 23,
      want: [[12, 1, 10]],
    },
    { name: "No path", root: TWO_PATHS, sum: 100, want: [] },
    {
      name: "Two paths",
      root: TWO_PATHS,
      sum: 22,
      want: [
        [5, 4, 11, 2],
        [5, 8, 4, 5],
      ],
    },
    { name: "Empty tree", root: [], sum: 0, want: [] },
  ])("$name", ({ root, sum, want }) => {
    expect(findPaths(tree(root), sum)).toEqual(want);
  });
});
