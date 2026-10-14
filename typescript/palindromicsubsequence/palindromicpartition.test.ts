import { describe, expect, test } from "vitest";

import { findMppCuts } from "./palindromicpartition.ts";

describe("findMppCuts", () => {
  test.each([
    { name: "Example 1", st: "abdbca", want: 3 },
    { name: "Example 2", st: "cddpd", want: 2 },
    { name: "Example 3", st: "pqr", want: 2 },
    { name: "Example 4", st: "pp", want: 0 },
  ])("$name", ({ st, want }) => {
    expect(findMppCuts(st)).toBe(want);
  });
});
