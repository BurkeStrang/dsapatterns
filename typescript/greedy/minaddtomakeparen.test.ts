import { describe, expect, test } from "vitest";

import { minAddToMakeValid } from "./minaddtomakeparen.ts";

describe("minAddToMakeValid", () => {
  test.each([
    { name: "Example 1", s: "(()", want: 1 },
    { name: "Example 2", s: "))((", want: 4 },
    { name: "Example 3", s: "(()())(", want: 1 },
    { name: "Already valid", s: "()()", want: 0 },
  ])("$name", ({ s, want }) => {
    expect(minAddToMakeValid(s)).toBe(want);
  });
});
