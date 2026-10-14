import { describe, expect, test } from "vitest";

import { findMissingNumber } from "./missingnumber.ts";

describe("findMissingNumber", () => {
  test.each([
    { name: "Example 1", arr: [1, 2, 3, 5], want: 4 },
    { name: "Example 2", arr: [1, 2, 4, 5], want: 3 },
    {
      name: "Example 3",
      arr: Array.from({ length: 20 }, (_, i) => i + 1),
      want: 21,
    },
  ])("$name", ({ arr, want }) => {
    expect(findMissingNumber(arr)).toBe(want);
  });
});
