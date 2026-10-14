import { describe, expect, test } from "vitest";

import { findSlidingWindowMedian } from "./slidingwindowmedian.ts";

describe("findSlidingWindowMedian", () => {
  test.each([
    { name: "k=2", nums: [1, 2, -1, 3, 5], k: 2, want: [1.5, 0.5, 1.0, 4.0] },
    { name: "k=3", nums: [1, 2, -1, 3, 5], k: 3, want: [1.0, 2.0, 3.0] },
    {
      name: "single element window",
      nums: [4, 1, 3],
      k: 1,
      want: [4.0, 1.0, 3.0],
    },
  ])("$name", ({ nums, k, want }) => {
    const got = findSlidingWindowMedian(nums, k);
    expect(got).toHaveLength(want.length);
    got.forEach((value, i) => {
      expect(value).toBeCloseTo(want[i], 9);
    });
  });
});
