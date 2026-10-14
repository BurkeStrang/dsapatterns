import { describe, expect, test } from "vitest";

import { canPartition } from "./equalsumpartition.ts";

describe("canPartition", () => {
  test.each([
    { name: "Example 1", nums: [1, 2, 3, 4], want: true },
    { name: "Example 2", nums: [1, 1, 3, 4, 7], want: true },
    { name: "Example 3", nums: [2, 3, 4, 6], want: false },
  ])("$name", ({ nums, want }) => {
    expect(canPartition(nums)).toBe(want);
  });
});
