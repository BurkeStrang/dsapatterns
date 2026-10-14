import { describe, expect, test } from "vitest";

import { findDup } from "./finddup.ts";

describe("findDup", () => {
  test.each([
    { name: "Example 1", nums: [1, 4, 4, 3, 2], want: 4 },
    { name: "Example 2", nums: [2, 1, 3, 3, 5, 4], want: 3 },
    { name: "Example 3", nums: [2, 4, 1, 4, 4], want: 4 },
  ])("$name", ({ nums, want }) => {
    expect(findDup(nums)).toBe(want);
  });
});
