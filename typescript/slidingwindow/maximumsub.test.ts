import { describe, expect, test } from "vitest";

import { findMaxSumSubArray } from "./maximumsub.ts";

describe("findMaxSumSubArray", () => {
  test.each([
    { name: "basic case", k: 3, arr: [2, 1, 5, 1, 3, 2], want: 9 },
    { name: "single element window", k: 1, arr: [4, 2, 7, 1], want: 7 },
    { name: "window equals array length", k: 4, arr: [1, 2, 3, 4], want: 10 },
    { name: "empty array", k: 3, arr: [], want: 0 },
  ])("$name", ({ k, arr, want }) => {
    expect(findMaxSumSubArray(k, arr)).toBe(want);
  });
});
