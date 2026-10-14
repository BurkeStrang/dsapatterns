import { describe, expect, test } from "vitest";

import { countWays } from "./staircase.ts";

describe("countWays", () => {
  test.each([
    { name: "Example 1", n: 3, want: 4 },
    { name: "Example 2", n: 4, want: 7 },
  ])("$name", ({ n, want }) => {
    expect(countWays(n)).toBe(want);
  });
});
