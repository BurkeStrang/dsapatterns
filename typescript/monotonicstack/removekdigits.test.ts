import { describe, expect, test } from "vitest";

import { removeKdigits } from "./removekdigits.ts";

describe("removeKdigits", () => {
  test.each([
    { name: "Example 1", num: "1432219", k: 3, want: "1219" },
    { name: "Example 2", num: "10200", k: 1, want: "200" },
    { name: "Example 3", num: "1901042", k: 4, want: "2" },
    { name: "Remove all digits", num: "10", k: 2, want: "0" },
    { name: "Leading zeros after removal", num: "100200", k: 1, want: "200" },
    { name: "No removal needed", num: "12345", k: 0, want: "12345" },
  ])("$name", ({ num, k, want }) => {
    expect(removeKdigits(num, k)).toBe(want);
  });
});
