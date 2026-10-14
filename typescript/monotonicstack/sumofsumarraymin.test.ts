import { describe, expect, test } from "vitest";

import { sumSubarrayMins } from "./sumofsumarraymin.ts";

describe("sumSubarrayMins", () => {
  test.each([
    { name: "Example 1", arr: [3, 1, 2, 4, 5], want: 30 },
    { name: "Example 2", arr: [2, 6, 5, 4], want: 36 },
    { name: "Example 3", arr: [7, 3, 8], want: 27 },
    { name: "Single element", arr: [5], want: 5 },
    { name: "All same elements", arr: [2, 2, 2], want: 12 },
  ])("$name", ({ arr, want }) => {
    expect(sumSubarrayMins(arr)).toBe(want);
  });
});
