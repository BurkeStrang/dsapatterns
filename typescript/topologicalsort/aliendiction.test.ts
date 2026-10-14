import { describe, expect, test } from "vitest";

import { findAlienOrder } from "./aliendiction.ts";

describe("findAlienOrder", () => {
  test.each([
    { name: "Example 1", words: ["ba", "bc", "ac", "cab"], want: "bac" },
    { name: "Example 2", words: ["cab", "aaa", "aab"], want: "cab" },
    {
      name: "Example 3",
      words: ["ywx", "wz", "xww", "xz", "zyy", "zwz"],
      want: "ywxz",
    },
    { name: "Word before its own prefix", words: ["abc", "ab"], want: "" },
    { name: "Cyclic ordering", words: ["a", "b", "a"], want: "" },
    { name: "No words", words: [], want: "" },
  ])("$name", ({ words, want }) => {
    expect(findAlienOrder(words)).toBe(want);
  });
});
