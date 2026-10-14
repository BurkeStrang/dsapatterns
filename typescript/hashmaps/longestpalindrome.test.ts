import { describe, expect, test } from "vitest";

import { longestPalindrome } from "./longestpalindrome.ts";

describe("longestPalindrome", () => {
  test.each([
    { name: "applepie", s: "applepie", want: 5 },
    { name: "aabbcc", s: "aabbcc", want: 6 },
    { name: "bananas", s: "bananas", want: 5 },
    { name: "single character", s: "a", want: 1 },
    { name: "all unique", s: "abcdef", want: 1 },
    { name: "all pairs", s: "aabb", want: 4 },
  ])("$name", ({ s, want }) => {
    expect(longestPalindrome(s)).toBe(want);
  });
});
