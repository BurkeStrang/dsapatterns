import { describe, expect, test } from "vitest";

import { maxLengthReplace } from "./maxsubstringkreplace.ts";

describe("maxLengthReplace", () => {
  test.each([
    { name: "Example 1", s: "aabccbb", k: 2, want: 5 },
    { name: "Example 2", s: "abbcb", k: 1, want: 4 },
    { name: "Example 3", s: "abccde", k: 1, want: 3 },
  ])("$name", ({ s, k, want }) => {
    expect(maxLengthReplace(s, k)).toBe(want);
  });
});
