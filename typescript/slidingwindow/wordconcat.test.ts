import { describe, expect, test } from "vitest";

import { findWordConcatenation } from "./wordconcat.ts";

describe("findWordConcatenation", () => {
  test.each([
    { name: "Example 1", s: "catfoxcat", words: ["cat", "fox"], want: [0, 3] },
    { name: "Example 2", s: "catcatfoxfox", words: ["cat", "fox"], want: [3] },
    { name: "No match", s: "abcdefg", words: ["hi", "jk"], want: [] },
  ])("$name", ({ s, words, want }) => {
    expect(findWordConcatenation(s, words)).toEqual(want);
  });
});
