import { describe, expect, test } from "vitest";

import { firstUniqChar } from "./firstnonrepeatingchar.ts";

describe("firstUniqChar", () => {
  test.each([
    { name: "Example 1: apple", s: "apple", want: 0 },
    { name: "Example 2: abcab", s: "abcab", want: 2 },
    { name: "Example 3: abab", s: "abab", want: -1 },
    { name: "Single character", s: "z", want: 0 },
    { name: "All unique", s: "abcdef", want: 0 },
    { name: "Last unique", s: "aabbc", want: 4 },
  ])("$name", ({ s, want }) => {
    expect(firstUniqChar(s)).toBe(want);
  });
});
