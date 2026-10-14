import { describe, expect, test } from "vitest";

import { findMinimumDeletions } from "./mindeletiontomakepal.ts";

describe("findMinimumDeletions", () => {
  test.each([
    { name: "Example 1", st: "abdbca", want: 1 },
    { name: "Example 2", st: "cddpd", want: 2 },
    { name: "Example 3", st: "pqr", want: 2 },
    { name: "Empty string", st: "", want: 0 },
  ])("$name", ({ st, want }) => {
    expect(findMinimumDeletions(st)).toBe(want);
  });
});
