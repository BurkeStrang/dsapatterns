import { describe, expect, test } from "vitest";

import { validParentheses } from "./balancedparentheses.ts";

describe("validParentheses", () => {
  test.each([
    { name: "Example 1 - balanced", s1: "{[()]}", want: true },
    { name: "Example 2 - not balanced", s1: "{[}]", want: false },
    { name: "Example 3 - not balanced", s1: "(]", want: false },
    { name: "Empty string - balanced", s1: "", want: true },
    { name: "Single type - balanced", s1: "()[]{}", want: true },
    { name: "Single type - not balanced", s1: "(((", want: false },
  ])("$name", ({ s1, want }) => {
    expect(validParentheses(s1)).toBe(want);
  });
});
