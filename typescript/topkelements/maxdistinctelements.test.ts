import { describe, expect, test } from "vitest";

import { findMaximumDistinctElements } from "./maxdistinctelements.ts";

describe("findMaximumDistinctElements", () => {
  test.each([
    { name: "Example 1", nums: [7, 3, 5, 8, 5, 3, 3], k: 2, want: 3 },
    { name: "Example 2", nums: [3, 5, 12, 11, 12], k: 3, want: 2 },
    {
      name: "Example 3",
      nums: [1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5],
      k: 2,
      want: 3,
    },
  ])("$name", ({ nums, k, want }) => {
    expect(findMaximumDistinctElements(nums, k)).toBe(want);
  });
});
