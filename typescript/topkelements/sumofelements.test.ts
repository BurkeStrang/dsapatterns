import { describe, expect, test } from "vitest";

import { findSumOfElements } from "./sumofelements.ts";

describe("findSumOfElements", () => {
  test.each([
    { name: "basic test", nums: [1, 3, 12, 5, 15, 11], k1: 3, k2: 6, want: 23 },
    { name: "second test", nums: [3, 5, 8, 7], k1: 1, k2: 4, want: 12 },
  ])("$name", ({ nums, k1, k2, want }) => {
    expect(findSumOfElements(nums, k1, k2)).toBe(want);
  });
});
