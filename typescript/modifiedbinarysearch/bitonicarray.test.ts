import { describe, expect, test } from "vitest";

import { searchBitonic } from "./bitonicarray.ts";

describe("searchBitonic", () => {
  test.each([
    { name: "Example 1", arr: [1, 3, 8, 4, 3], key: 4, want: 3 },
    { name: "Example 2", arr: [3, 8, 3, 1], key: 8, want: 1 },
    { name: "Example 3", arr: [1, 3, 8, 12], key: 12, want: 3 },
    { name: "Example 4", arr: [10, 9, 8], key: 10, want: 0 },
  ])("$name", ({ arr, key, want }) => {
    expect(searchBitonic(arr, key)).toBe(want);
  });
});
