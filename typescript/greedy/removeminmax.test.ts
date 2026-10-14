import { describe, expect, test } from "vitest";

import { minMoves } from "./removeminmax.ts";

describe("minMoves", () => {
  test.each([
    { name: "Example 1", nums: [3, 2, 5, 1, 4], want: 3 },
    { name: "Example 2", nums: [7, 5, 6, 8, 1], want: 2 },
    { name: "Single element", nums: [9], want: 1 },
  ])("$name", ({ nums, want }) => {
    expect(minMoves(nums)).toBe(want);
  });
});
