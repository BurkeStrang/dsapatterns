import { describe, expect, test } from "vitest";

import { findPermutation } from "./permutationsinstring.ts";

describe("findPermutation", () => {
  test.each([
    { name: "Example 1", s: "oidbcaf", pattern: "abc", want: true },
    { name: "Example 2", s: "odicf", pattern: "dc", want: false },
    { name: "Example 3", s: "bcdxabcdy", pattern: "bcdyabcdx", want: true },
    { name: "Example 4", s: "aaacb", pattern: "abc", want: true },
  ])("$name", ({ s, pattern, want }) => {
    expect(findPermutation(s, pattern)).toBe(want);
  });
});
