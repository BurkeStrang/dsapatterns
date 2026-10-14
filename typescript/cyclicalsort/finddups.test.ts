import { describe, expect, test } from "vitest";

import { findDups } from "./finddups.ts";

describe("findDups", () => {
  test.each([
    { name: "Example 1", nums: [3, 4, 4, 5, 5], want: [5, 4] },
    { name: "Example 2", nums: [5, 4, 7, 2, 3, 5, 3], want: [3, 5] },
  ])("$name", ({ nums, want }) => {
    expect(findDups(nums)).toEqual(want);
  });
});
