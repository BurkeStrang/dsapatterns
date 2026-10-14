import { describe, expect, test } from "vitest";

import { findSubstring } from "./smallestwindowsubstring.ts";

describe("findSubstring", () => {
  test.each([
    { name: "Example 1", s: "aabdec", pattern: "abc", want: "abdec" },
    { name: "Example 2", s: "aabdec", pattern: "abac", want: "aabdec" },
    { name: "Example 3", s: "abdbca", pattern: "abc", want: "bca" },
    { name: "Example 4", s: "adcad", pattern: "abc", want: "" },
  ])("$name", ({ s, pattern, want }) => {
    expect(findSubstring(s, pattern)).toBe(want);
  });
});
