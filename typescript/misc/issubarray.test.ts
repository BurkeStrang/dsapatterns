import { describe, expect, test } from "vitest";

import { isSubarray } from "./issubarray.ts";

describe("isSubarray", () => {
  test.each([
    { name: "Example 1", nums: [1, 2, 3], sub: [2, 3], want: true },
    {
      name: "Same numbers, not next to each other",
      nums: [1, 2, 3],
      sub: [1, 3],
      want: false,
    },
    {
      name: "Longer than the array",
      nums: [1, 2],
      sub: [1, 2, 3],
      want: false,
    },
    { name: "Empty subarray", nums: [1, 2], sub: [], want: true },
  ])("$name", ({ nums, sub, want }) => {
    expect(isSubarray(nums, sub)).toBe(want);
  });
});
