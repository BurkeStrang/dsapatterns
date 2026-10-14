import { describe, expect, test } from "vitest";

import { findMinSubArray } from "./smallestarraygreatestsum.ts";

describe("findMinSubArray", () => {
  test.each([
    { name: "Example 1", s: 7, arr: [2, 1, 5, 2, 3, 2], want: 2 },
    { name: "Example 2", s: 7, arr: [2, 1, 5, 2, 8], want: 1 },
    { name: "Example 3", s: 8, arr: [3, 4, 1, 1, 6], want: 3 },
    { name: "No subarray meets S", s: 20, arr: [1, 2, 3, 4], want: 0 },
  ])("$name", ({ s, arr, want }) => {
    expect(findMinSubArray(s, arr)).toBe(want);
  });
});
