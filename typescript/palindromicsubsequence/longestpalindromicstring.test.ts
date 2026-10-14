import { describe, expect, test } from "vitest";

import { findLpStringLength } from "./longestpalindromicstring.ts";

describe("findLpStringLength", () => {
  test.each([
    { name: "Example 1", st: "abdbca", want: 3 },
    { name: "Example 2", st: "cddpd", want: 3 },
    { name: "Example 3", st: "pqr", want: 1 },
  ])("$name", ({ st, want }) => {
    expect(findLpStringLength(st)).toBe(want);
  });
});
