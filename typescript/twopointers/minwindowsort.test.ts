import { describe, expect, test } from "vitest";

import { minSort } from "./minwindowsort.ts";

describe("minSort", () => {
  test.each([
    { name: "Example 1", arr: [1, 2, 5, 3, 7, 10, 9, 12], want: 5 },
    { name: "Example 2", arr: [1, 3, 2, 0, -1, 7, 10], want: 5 },
    { name: "Example 3", arr: [1, 2, 3], want: 0 },
    { name: "Example 4", arr: [3, 2, 1], want: 3 },
  ])("$name", ({ arr, want }) => {
    expect(minSort(arr)).toBe(want);
  });
});
