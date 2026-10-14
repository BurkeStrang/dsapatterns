import { describe, expect, test } from "vitest";

import { findMaxSteal } from "./housetheif.ts";

describe("findMaxSteal", () => {
  test.each([
    { name: "Example 1", wealth: [2, 5, 1, 3, 6, 2, 4], want: 15 },
    { name: "Example 2", wealth: [2, 10, 14, 8, 1], want: 18 },
  ])("$name", ({ wealth, want }) => {
    expect(findMaxSteal(wealth)).toBe(want);
  });
});
