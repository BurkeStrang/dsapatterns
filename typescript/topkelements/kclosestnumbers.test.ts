import { describe, expect, test } from "vitest";

import { findClosestElements } from "./kclosestnumbers.ts";

describe("findClosestElements", () => {
  test.each([
    { name: "Example 1", arr: [5, 6, 7, 8, 9], k: 3, x: 7, want: [6, 7, 8] },
    { name: "Example 2", arr: [2, 4, 5, 6, 9], k: 3, x: 6, want: [4, 5, 6] },
    { name: "Example 3", arr: [2, 4, 5, 6, 9], k: 3, x: 10, want: [5, 6, 9] },
  ])("$name", ({ arr, k, x, want }) => {
    expect(findClosestElements(arr, k, x)).toEqual(want);
  });
});
