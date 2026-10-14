import { describe, expect, test } from "vitest";

import { findCorrupt } from "./corruptpair.ts";

describe("findCorrupt", () => {
  test.each([
    { name: "Example 1", nums: [3, 1, 2, 5, 2], want: [2, 4] },
    { name: "Example 2", nums: [3, 1, 2, 3, 6, 4], want: [3, 5] },
  ])("$name", ({ nums, want }) => {
    expect(findCorrupt(nums)).toEqual(want);
  });
});
