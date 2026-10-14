import { describe, expect, test } from "vitest";

import { findLength } from "./longestsubstringwithkchars.ts";

describe("findLength", () => {
  test.each([
    { name: "Example 1", s: "araaci", k: 2, want: 4 },
    { name: "Example 2", s: "araaci", k: 1, want: 2 },
    { name: "Example 3", s: "cbbebi", k: 3, want: 5 },
  ])("$name", ({ s, k, want }) => {
    expect(findLength(s, k)).toBe(want);
  });
});
