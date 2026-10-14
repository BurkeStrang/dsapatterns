import { describe, expect, test } from "vitest";

import { findSingleNumbers } from "./twosinglenumbers.ts";

describe("findSingleNumbers", () => {
  test.each([
    { name: "Example 1", nums: [1, 4, 2, 1, 3, 5, 6, 2, 3, 5], want: [4, 6] },
    { name: "Example 2", nums: [2, 1, 3, 2], want: [1, 3] },
  ])("$name", ({ nums, want }) => {
    // the two numbers may come back in either order
    const got = findSingleNumbers(nums).sort((a, b) => a - b);
    expect(got).toEqual(want);
  });
});
