import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { findSuccessor } from "./levelordersuccesor.ts";

describe("findSuccessor", () => {
  // want is the value of the successor
  test.each([
    { name: "Example 1", root: [1, 2, 3, 4, 5], key: 3, want: 4 },
    { name: "Example 2", root: [12, 7, 1, 9, null, 10, 5], key: 9, want: 10 },
    { name: "Example 3", root: [12, 7, 1, 9, null, 10, 5], key: 12, want: 7 },
    { name: "No successor (last node)", root: [1, 2], key: 2, want: null },
    { name: "Empty tree", root: [], key: 1, want: null },
  ])("$name", ({ root, key, want }) => {
    expect(findSuccessor(tree(root), key)?.value ?? null).toBe(want);
  });
});
