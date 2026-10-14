import { describe, expect, test } from "vitest";

import { countRotations } from "./rotationcount.ts";

describe("countRotations", () => {
  test.each([
    { name: "Example 1", arr: [10, 15, 1, 3, 8], want: 2 },
    { name: "Example 2", arr: [4, 5, 7, 9, 10, -1, 2], want: 5 },
    { name: "Example 3", arr: [1, 3, 8, 10], want: 0 },
  ])("$name", ({ arr, want }) => {
    expect(countRotations(arr)).toBe(want);
  });
});
