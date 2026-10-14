import { describe, expect, test } from "vitest";

import { findMinFee } from "./minjumpswithfee.ts";

describe("findMinFee", () => {
  test.each([
    { name: "Example 1", fee: [1, 2, 5, 2, 1, 2], want: 3 },
    { name: "Example 2", fee: [2, 3, 4, 5], want: 5 },
  ])("$name", ({ fee, want }) => {
    expect(findMinFee(fee)).toBe(want);
  });
});
