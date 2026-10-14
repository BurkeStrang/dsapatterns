import { describe, expect, test } from "vitest";

import { findTriplets } from "./tripletwithsmallersum.ts";

describe("findTriplets", () => {
  test.each([
    { name: "Example 1", arr: [-1, 0, 2, 3], target: 3, want: 2 },
    { name: "Example 2", arr: [-1, 4, 2, 1, 3], target: 5, want: 4 },
    { name: "empty", arr: [], target: 5, want: 0 },
    { name: "two numbers", arr: [1, 2], target: 3, want: 0 },
  ])("$name", ({ arr, target, want }) => {
    expect(findTriplets(arr, target)).toBe(want);
  });
});
