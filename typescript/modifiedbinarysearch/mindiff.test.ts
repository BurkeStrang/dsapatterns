import { describe, expect, test } from "vitest";

import { searchMinDiff } from "./mindiff.ts";

describe("searchMinDiff", () => {
  test.each([
    { name: "Example 1", arr: [4, 6, 10], key: 7, want: 6 },
    { name: "Example 2", arr: [4, 6, 10], key: 4, want: 4 },
    { name: "Example 3", arr: [1, 3, 8, 10, 15], key: 12, want: 10 },
    { name: "Example 4", arr: [4, 6, 10], key: 17, want: 10 },
  ])("$name", ({ arr, key, want }) => {
    expect(searchMinDiff(arr, key)).toBe(want);
  });
});
