import { describe, expect, test } from "vitest";

import { nextGreaterElement } from "./nextgreaterelement.ts";

describe("nextGreaterElement", () => {
  test.each([
    {
      name: "Example 1",
      nums1: [4, 2, 6],
      nums2: [6, 2, 4, 5, 3, 7],
      want: [5, 4, 7],
    },
    {
      name: "Example 2",
      nums1: [9, 7, 1],
      nums2: [1, 7, 9, 5, 4, 3],
      want: [-1, 9, 7],
    },
    {
      name: "Example 3",
      nums1: [5, 12, 3],
      nums2: [12, 3, 5, 4, 10, 15],
      want: [10, 15, 5],
    },
    { name: "No greater element", nums1: [8], nums2: [8, 7, 6], want: [-1] },
    {
      name: "All increasing",
      nums1: [1, 2, 3],
      nums2: [1, 2, 3, 4],
      want: [2, 3, 4],
    },
  ])("$name", ({ nums1, nums2, want }) => {
    expect(nextGreaterElement(nums1, nums2)).toEqual(want);
  });
});
