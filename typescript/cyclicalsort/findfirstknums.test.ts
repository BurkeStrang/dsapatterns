import { describe, expect, test } from "vitest";

import { findFirstK } from "./findfirstknums.ts";

describe("findFirstK", () => {
  test.each([
    { name: "Example 1", nums: [3, -1, 4, 5, 5], k: 3, want: [1, 2, 6] },
    { name: "Example 2", nums: [2, 3, 4], k: 3, want: [1, 5, 6] },
    { name: "Example 3", nums: [-2, -3, 4], k: 2, want: [1, 2] },
  ])("$name", ({ nums, k, want }) => {
    expect(findFirstK(nums, k)).toEqual(want);
  });
});
