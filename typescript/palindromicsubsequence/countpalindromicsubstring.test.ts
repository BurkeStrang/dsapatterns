import { describe, expect, test } from "vitest";

import { findCps } from "./countpalindromicsubstring.ts";

describe("findCps", () => {
  test.each([
    { name: "Example 1", st: "abdbca", want: 7 },
    { name: "Example 2", st: "cddpd", want: 7 },
    { name: "Example 3", st: "pqr", want: 3 },
    { name: "Empty string", st: "", want: 0 },
  ])("$name", ({ st, want }) => {
    expect(findCps(st)).toBe(want);
  });
});
