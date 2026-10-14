import { describe, expect, test } from "vitest";

import { findKLargestPairs } from "./kpairslargestsum.ts";

describe("findKLargestPairs", () => {
  // the pairs come back with the smallest sum first; pairs with the same sum
  // come back in the order of their numbers
  test.each([
    {
      name: "Example 1",
      nums1: [9, 8, 2],
      nums2: [6, 3, 1],
      k: 3,
      want: [
        [9, 3],
        [8, 6],
        [9, 6],
      ],
    },
    {
      name: "Example 2",
      nums1: [5, 2, 1],
      nums2: [2, -1],
      k: 3,
      want: [
        [2, 2],
        [5, -1],
        [5, 2],
      ],
    },
  ])("$name", ({ nums1, nums2, k, want }) => {
    expect(findKLargestPairs(nums1, nums2, k)).toEqual(want);
  });
});
