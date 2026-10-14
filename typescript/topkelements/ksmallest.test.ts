import { describe, expect, test } from "vitest";

import { findKthSmallestNumber } from "./ksmallest.ts";

describe("findKthSmallestNumber", () => {
  test.each([
    { name: "Example 1", nums: [1, 5, 12, 2, 11, 5], k: 3, want: 5 },
    { name: "Example 2", nums: [1, 5, 12, 2, 11, 5], k: 4, want: 5 },
    { name: "Example 3", nums: [5, 12, 11, -1, 12], k: 3, want: 11 },
    { name: "Example 4", nums: [1, 5, 12, 2, 11, 5], k: 1, want: 1 },
  ])("$name", ({ nums, k, want }) => {
    expect(findKthSmallestNumber(nums, k)).toBe(want);
  });
});
