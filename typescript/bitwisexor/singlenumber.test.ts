import { describe, expect, test } from "vitest";

import { findSingleNumber } from "./singlenumber.ts";

describe("findSingleNumber", () => {
  test.each([
    { name: "Example 1", arr: [1, 4, 2, 1, 3, 2, 3], want: 4 },
    { name: "Example 2", arr: [7, 9, 7], want: 9 },
    { name: "Example 3", arr: [5, 6, 7, 5, 6], want: 7 },
  ])("$name", ({ arr, want }) => {
    expect(findSingleNumber(arr)).toBe(want);
  });
});
