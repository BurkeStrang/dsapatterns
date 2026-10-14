import { describe, expect, test } from "vitest";

import { decimalToBinary } from "./decimaltobinary.ts";

describe("decimalToBinary", () => {
  test.each([
    { name: "Example 1", num: 2, want: "10" },
    { name: "Example 2", num: 7, want: "111" },
    { name: "Example 3", num: 18, want: "10010" },
  ])("$name", ({ num, want }) => {
    expect(decimalToBinary(num)).toBe(want);
  });
});
