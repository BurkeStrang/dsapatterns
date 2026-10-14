import { describe, expect, test } from "vitest";

import { findStringAnagrams } from "./stringanagrams.ts";

describe("findStringAnagrams", () => {
  test.each([
    { name: "Example 1", s: "ppqp", pattern: "pq", want: [1, 2] },
    { name: "Example 2", s: "abbcabc", pattern: "abc", want: [2, 3, 4] },
  ])("$name", ({ s, pattern, want }) => {
    expect(findStringAnagrams(s, pattern)).toEqual(want);
  });
});
