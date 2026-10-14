import { describe, expect, test } from "vitest";

import { findMis } from "./findminmissingposnum.ts";

describe("findMis", () => {
  test.each([
    { name: "Example 1", nums: [-3, 1, 5, 4, 2], want: 3 },
    { name: "Example 2", nums: [3, -2, 0, 1, 2], want: 4 },
    { name: "Example 3", nums: [3, 2, 5, 1], want: 4 },
    { name: "Example 4", nums: [33, 37, 5], want: 1 },
  ])("$name", ({ nums, want }) => {
    expect(findMis(nums)).toBe(want);
  });
});
