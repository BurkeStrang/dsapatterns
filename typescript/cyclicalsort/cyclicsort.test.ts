import { describe, expect, test } from "vitest";

import { sort } from "./cyclicsort.ts";

describe("sort", () => {
  test.each([
    { name: "Example 1", nums: [3, 1, 5, 4, 2], want: [1, 2, 3, 4, 5] },
    { name: "Example 2", nums: [2, 6, 4, 3, 1, 5], want: [1, 2, 3, 4, 5, 6] },
    { name: "Example 3", nums: [1, 5, 6, 4, 3, 2], want: [1, 2, 3, 4, 5, 6] },
  ])("$name", ({ nums, want }) => {
    sort(nums);
    expect(nums).toEqual(want);
  });
});
