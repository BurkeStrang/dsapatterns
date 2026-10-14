import { describe, expect, test } from "vitest";

import { maxUniqueSplit } from "./maxunqiuesubstrings.ts";

describe("maxUniqueSplit", () => {
  test.each([
    { name: "Example 1", s: "ababccc", want: 5 },
    { name: "Example 2", s: "aba", want: 2 },
    { name: "Example 3", s: "aa", want: 1 },
  ])("$name", ({ s, want }) => {
    expect(maxUniqueSplit(s)).toBe(want);
  });
});
