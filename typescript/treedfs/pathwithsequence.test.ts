import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { findPath } from "./pathwithsequence.ts";

describe("findPath", () => {
  test.each([
    {
      name: "Example 1: Path exists",
      root: [1, 7, 9, null, null, 2, 9],
      sequence: [1, 9, 9],
      want: true,
    },
    {
      name: "Example 2: Path does not exist",
      root: [1, 0, 1, 1, 6, null, 5],
      sequence: [1, 0, 7],
      want: false,
    },
    {
      name: "Example 3: Empty sequence",
      root: [1, 2],
      sequence: [],
      want: false,
    },
    { name: "Example 4: Empty tree", root: [], sequence: [1], want: false },
    {
      name: "Example 5: Single node match",
      root: [5],
      sequence: [5],
      want: true,
    },
  ])("$name", ({ root, sequence, want }) => {
    expect(findPath(tree(root), sequence)).toBe(want);
  });
});
