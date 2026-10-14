import { describe, expect, test } from "vitest";

import { searchRotated } from "./rotatedarray.ts";

describe("searchRotated", () => {
  test.each([
    { name: "Example 1", arr: [10, 15, 1, 3, 8], key: 15, want: 1 },
    { name: "Example 2", arr: [4, 5, 7, 9, 10, -1, 2], key: 10, want: 4 },
    { name: "Example 3", arr: [10, 15, 1, 3, 8], key: 100, want: -1 },
    { name: "Example 4", arr: [10, 15, 1, 3, 8], key: 1, want: 2 },
  ])("$name", ({ arr, key, want }) => {
    expect(searchRotated(arr, key)).toBe(want);
  });
});
