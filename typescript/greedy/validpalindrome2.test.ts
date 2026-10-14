import { describe, expect, test } from "vitest";

import { isPalindromePossible } from "./validpalindrome2.ts";

describe("isPalindromePossible", () => {
  test.each([
    { name: "Example 1", input: "racecar", want: true },
    { name: "Example 2", input: "abeccdeba", want: true },
    { name: "Example 3", input: "abcdef", want: false },
    { name: "Empty string", input: "", want: true },
  ])("$name", ({ input, want }) => {
    expect(isPalindromePossible(input)).toBe(want);
  });
});
