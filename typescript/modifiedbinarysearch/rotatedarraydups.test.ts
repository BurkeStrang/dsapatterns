import { describe, expect, test } from "vitest";

import { searchRotatedDups } from "./rotatedarraydups.ts";

describe("searchRotatedDups", () => {
  test.each([
    { name: "Example 1", arr: [3, 7, 3, 3, 3], key: 7, want: 1 },
    { name: "Example 2", arr: [3, 3, 3, 7, 3], key: 7, want: 3 },
    { name: "Example 3", arr: [3, 3, 7, 3, 3], key: 7, want: 2 },
  ])("$name", ({ arr, key, want }) => {
    expect(searchRotatedDups(arr, key)).toBe(want);
  });
});
