import { describe, expect, test } from "vitest";

import { findSubarrayCount } from "./subscountlessthantarget.ts";

describe("findSubarrayCount", () => {
  test.each([
    { name: "Example 1", nums: [2, 5, 3, 10], target: 30, want: 6 },
    { name: "Example 2", nums: [8, 2, 6, 5], target: 50, want: 7 },
    { name: "Example 3 (target 0)", nums: [10, 5, 2, 6], target: 0, want: 0 },
    { name: "Single element < target", nums: [1], target: 2, want: 1 },
    { name: "Single element >= target", nums: [5], target: 5, want: 0 },
  ])("$name", ({ nums, target, want }) => {
    expect(findSubarrayCount(nums, target)).toBe(want);
  });
});
