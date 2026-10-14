import { describe, expect, test } from "vitest";

import { findMissingNumber } from "./findmissingnum.ts";

describe("findMissingNumber", () => {
  test.each([
    { name: "Example 1", nums: [4, 0, 3, 1], want: 2 },
    { name: "Example 2", nums: [8, 3, 5, 2, 4, 6, 0, 1], want: 7 },
  ])("$name", ({ nums, want }) => {
    expect(findMissingNumber(nums)).toBe(want);
  });
});
