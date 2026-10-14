import { describe, expect, test } from "vitest";

import { countSubsets } from "./countofsubsetsum.ts";

describe("countSubsets", () => {
  test.each([
    { name: "Example 1", num: [1, 1, 2, 3], sum: 4, want: 3 },
    { name: "Example 2", num: [1, 2, 7, 1, 5], sum: 9, want: 3 },
  ])("$name", ({ num, sum, want }) => {
    expect(countSubsets(num, sum)).toBe(want);
  });
});
