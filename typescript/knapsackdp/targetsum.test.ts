import { describe, expect, test } from "vitest";

import { findTargetSubsets } from "./targetsum.ts";

describe("findTargetSubsets", () => {
  test.each([
    { name: "Example 1", num: [1, 1, 2, 3], s: 1, want: 3 },
    { name: "Example 2", num: [1, 2, 7, 1], s: 9, want: 2 },
  ])("$name", ({ num, s, want }) => {
    expect(findTargetSubsets(num, s)).toBe(want);
  });
});
