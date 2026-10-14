import { describe, expect, test } from "vitest";

import { largestPalindromic } from "./largestpalindromicnumber.ts";

describe("largestPalindromic", () => {
  test.each([
    { name: "Example 1", s: "323211444", want: "432141234" },
    { name: "Example 2", s: "998877", want: "987789" },
    { name: "Example 3", s: "54321", want: "5" },
    { name: "Only zeros", s: "000", want: "0" },
    { name: "Zeros in the middle", s: "10001", want: "10001" },
  ])("$name", ({ s, want }) => {
    expect(largestPalindromic(s)).toBe(want);
  });
});
