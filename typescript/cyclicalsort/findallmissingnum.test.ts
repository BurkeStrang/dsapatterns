import { describe, expect, test } from "vitest";

import { findNumbers } from "./findallmissingnum.ts";

describe("findNumbers", () => {
  test.each([
    { name: "Example 1", nums: [2, 3, 1, 8, 2, 3, 5, 1], want: [4, 6, 7] },
    { name: "Example 2", nums: [2, 4, 1, 2], want: [3] },
    { name: "Example 3", nums: [2, 3, 2, 1], want: [4] },
  ])("$name", ({ nums, want }) => {
    expect(findNumbers(nums)).toEqual(want);
  });
});
