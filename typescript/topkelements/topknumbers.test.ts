import { describe, expect, test } from "vitest";

import { findKLargestNumbers } from "./topknumbers.ts";

describe("findKLargestNumbers", () => {
  test.each([
    { name: "Example 1", nums: [3, 1, 5, 12, 2, 11], k: 3, want: [5, 11, 12] },
    { name: "Example 2", nums: [5, 12, 11, -1, 12], k: 3, want: [11, 12, 12] },
    {
      name: "All negative",
      nums: [-3, -1, -5, -12, -2, -11],
      k: 3,
      want: [-3, -2, -1],
    },
  ])("$name", ({ nums, k, want }) => {
    // the numbers may come back in any order
    expect(findKLargestNumbers(nums, k).sort((a, b) => a - b)).toEqual(want);
  });
});
