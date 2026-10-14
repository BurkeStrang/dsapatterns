import { describe, expect, test } from "vitest";

import { largestUniqueNumber } from "./largestuniquenum.ts";

describe("largestUniqueNumber", () => {
  test.each([
    { name: "Example 1", a: [5, 7, 3, 7, 5, 8], want: 8 },
    { name: "Example 2", a: [1, 2, 3, 2, 1, 4, 4], want: 3 },
    { name: "Example 3", a: [9, 9, 8, 8, 7, 7], want: -1 },
  ])("$name", ({ a, want }) => {
    expect(largestUniqueNumber(a)).toBe(want);
  });
});
