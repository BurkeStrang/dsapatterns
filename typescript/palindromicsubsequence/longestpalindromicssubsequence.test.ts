import { describe, expect, test } from "vitest";

import { findLpsLength } from "./longestpalindromicssubsequence.ts";

describe("findLpsLength", () => {
  test.each([
    { name: "Example 1", st: "abdbca", want: 5 },
    { name: "Example 2", st: "cddpd", want: 3 },
    { name: "Example 3", st: "pqr", want: 1 },
    { name: "Empty string", st: "", want: 0 },
  ])("$name", ({ st, want }) => {
    expect(findLpsLength(st)).toBe(want);
  });
});
