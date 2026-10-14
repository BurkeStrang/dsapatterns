import { describe, expect, test } from "vitest";

import { canPartitionSum } from "./subsetsum.ts";

describe("canPartitionSum", () => {
  test.each([
    { name: "Example 1", nums: [1, 2, 3, 7], sum: 6, want: true },
    { name: "Example 2", nums: [1, 2, 7, 1, 5], sum: 10, want: true },
    { name: "Example 3", nums: [1, 3, 4, 8], sum: 6, want: false },
  ])("$name", ({ nums, sum, want }) => {
    expect(canPartitionSum(nums, sum)).toBe(want);
  });
});
