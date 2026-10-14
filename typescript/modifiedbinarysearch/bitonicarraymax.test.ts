import { describe, expect, test } from "vitest";

import { findMaxInBitonicArray } from "./bitonicarraymax.ts";

describe("findMaxInBitonicArray", () => {
  test.each([
    { name: "Example 1", arr: [1, 3, 8, 12, 4, 2], want: 12 },
    { name: "Example 2", arr: [3, 8, 3, 1], want: 8 },
    { name: "Example 3", arr: [1, 3, 8, 12], want: 12 },
    { name: "Example 4", arr: [10, 9, 8], want: 10 },
  ])("$name", ({ arr, want }) => {
    expect(findMaxInBitonicArray(arr)).toBe(want);
  });
});
